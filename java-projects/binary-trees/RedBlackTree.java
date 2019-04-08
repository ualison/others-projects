package treinando;


public class RedBlackTree<K extends Comparable<K>, V> extends BinarySearchTree<K, V> {
	
	private static final boolean RED = true;
	private static final boolean BLACK = false;

	class RBNode extends Node {
		boolean color; 
		public RBNode(K key, V value, int count, boolean color) {
			super(key, value, count);
			this.color = color;
		}
	}
	
	private boolean isRed(Node node) {
		if (node == null) return BLACK;
		return getColor(node) == RED;
	}
	
	private Node rotateLeft(Node h) {
		Node x = h.right;
		h.right = x.left;
		x.left = h;
		setColor(x, getColor(h));
		setColor(h, RED);
		return x;
	}
	
	private Node rotateRight(Node h) {
		Node x = h.left;
		h.left = x.right;
		x.right = h;
		setColor(x, getColor(h));
		setColor(h, RED);
		return x;
	}
	
	private void flipColors(Node h) {
		setColor(h, RED);
		setColor(h.left, BLACK);
		setColor(h.right, BLACK);
	}
	
	@SuppressWarnings("unchecked")
	private void setColor(Node node, boolean color) {
		RBNode rbn = (RBNode) node;
		rbn.color = color;
	}
	
	@SuppressWarnings("unchecked")
	private boolean getColor(Node n) {
		RBNode rbn = (RBNode) n;
		return rbn.color;
	}
	
	  private Node moveRedLeft(Node h) {
	        flipColors(h);
	        if (isRed(h.right.left)) { 
	            h.right = rotateRight(h.right);
	            h = rotateLeft(h);
	            flipColors(h);
	        }
	        return h;
	    }

	    private Node moveRedRight(Node h) {
	        flipColors(h);
	        if (isRed(h.left.left)) { 
	            h = rotateRight(h);
	            flipColors(h);
	        }
	        return h;
	    }
	
	@Override
	public void put(K key, V value) {
		super.root = put(super.root, key, value);
		setColor(super.root, BLACK);
	}
	
	private Node put(Node r, K key, V value) {
		if (r == null) return new RBNode(key, value, 1, RED);
		int cmp = key.compareTo(r.key);
		if (cmp < 0) r.left = put(r.left, key, value);
		else if (cmp > 0) r.right = put(r.right, key, value);
		else r.value = value;
		
		if (!isRed(r.left) && isRed(r.right)) r = rotateLeft(r);
		if (isRed(r.left) && isRed(r.left.left)) r = rotateRight(r);
		if (isRed(r.left) && isRed(r.right)) flipColors(r);
		
		r.cont = size(r.left) + size(r.right) + 1;
		return r;
	}
	
	 @SuppressWarnings("unchecked")
	public void deleteMin() {
		 RBNode r = (RBNode) root;

	        if (!isRed(root.left) && !isRed(root.right))
	           r.color = RED;

	        root = deleteMin(root);
	        if (!isEmpty())  r.color = BLACK;
	    }

	    @SuppressWarnings("unchecked")
		protected Node deleteMin(Node h) { 
	        if (h.left == null)
	            return null;

	        if (!isRed(h.left) && !isRed(h.left.left))
	            h = (RBNode) moveRedLeft(h);

	        h.left = (RBNode)deleteMin(h.left);
	        return balance(h);
	    }


	    @SuppressWarnings("unchecked")
		public void delete(K key) { 
	        RBNode r = (RBNode) root;
	        if (!contains(key)) return;

	        if (!isRed(r.left) && !isRed(r.right))
	            r.color = RED;

	        r = (RBNode) delete(r, key);
	        if (!isEmpty()) r.color = BLACK;
	    }

	    private Node delete(Node h, K key) { 

	        if (key.compareTo(h.key) < 0)  {
	            if (!isRed(h.left) && !isRed(h.left.left))
	                h = moveRedLeft(h);
	            h.left = delete(h.left, key);
	        }
	        else {
	            if (isRed(h.left))
	                h = rotateRight(h);
	            if (key.compareTo(h.key) == 0 && (h.right == null))
	                return null;
	            if (!isRed(h.right) && !isRed(h.right.left))
	                h = moveRedRight(h);
	            if (key.compareTo(h.key) == 0) {
	                Node x = min(h.right);
	                h.key = x.key;
	                h.value = x.value;
	                h.right = deleteMin(h.right);
	            }
	            else h.right = delete(h.right, key);
	        }
	        return balance(h);
	    }
	    

	    public Node balance(Node h) {

	        if (isRed(h.right))                      h = rotateLeft(h);
	        if (isRed(h.left) && isRed(h.left.left)) h = rotateRight(h);
	        if (isRed(h.left) && isRed(h.right))     flipColors(h);

	       h.cont = size(h.left) + size(h.right) + 1;
	        return h;
	    }

	public static void main(String[] args) {
		RedBlackTree2<String, Integer> rbt = new RedBlackTree2<>();
		
		rbt.put("V", 9);
		rbt.put("S", 8);
		rbt.put("A", 5);
		rbt.put("F", 2);
		rbt.put("I", 11);
		rbt.put("E", 244);
		rbt.put("X", 75);
		rbt.put("Z", 96);
		rbt.put("W", 83);
		rbt.put("J", 51);
		rbt.put("H", 922);
		rbt.put("Y", 11);
		rbt.put("L", 22);
		rbt.put("M", 99);
		
		System.out.println(rbt.get("F"));
		System.out.println(rbt.get("E"));
		System.out.println(rbt.contains("E"));
		rbt.delete("E");
		System.out.println(rbt.contains("E"));


		
	}
}