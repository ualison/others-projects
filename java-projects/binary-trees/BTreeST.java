package treinando;


public class BTreeST<K extends Comparable<K>, V>{
	private Page<K, Object> root;
	private Page<K, Object> sentinelSon;

	public BTreeST(K sentinel, Object value) {
		root = new Page<>(true);
		sentinelSon = new Page<>(false);
		root.insert(sentinel, sentinelSon);
	}

	public boolean contains(K key) {
		return contains(root, key);
	}

	private boolean contains(Page<K, Object> r, K key) {
		if (r.isExternal())
			return r.holds(key);
		return contains(r.next(key), key);
	}

	public void add(K key, Object value) {
		add(root, key, value);
		if (root.hasOverflowed()) {
			Page<K, Object> left  = root;
			Page<K, Object> right = root.split();
			root = new Page<>(false);
			root.enter(left);
			root.enter(right);
		}
	}

	private void add(Page<K, Object> r, K key, Object value) {
		if (r.isExternal()) {
			r.insert(key, value);
			return;
		}
		
		Page<K, Object> next = r.next(key);
		add(next, key, value);
		if (next.hasOverflowed())
			r.enter(next.split());
	}

	public static void main(String[] args) {
		BTreeST<String, Integer> btree = new BTreeST<String, Integer>("*", 0);

		btree.add("K", 1);
		btree.add("A", 7);
		btree.add("B", 12);
		btree.add("H", 88);

		btree.add("Z", 7);
		btree.add("W", 12);
		btree.add("Q", 88);

	
		System.out.println(btree.contains("B"));

	}

}
