package treinando;

import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;



public class Page<K extends Comparable<K>, V> implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	private static final int M = 5;
	private boolean botton;
	
	BinarySearchST<K, Object> entry = new BinarySearchST<>();


	public Page(boolean botton) {
		this.botton = botton;
	}

	void close() {
		//NÃO FUNCIONA...
		try {
			FileOutputStream arquivoGrav = new FileOutputStream("C:/Users/Ualison/Desktop/Saída/page.dat");

			ObjectOutputStream objGravar = new ObjectOutputStream(arquivoGrav);

			objGravar.writeObject(this);
			objGravar.flush();
			objGravar.close();
			arquivoGrav.flush();
			arquivoGrav.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}       
	}

	@SuppressWarnings("unchecked")
	void insert(K key, V value) {
		if (key.equals("*")) {
			entry.put(key, value);

		} else {
			if (entry.size() < 2){
				entry.put(key, value);
               return;				
			}

			int cmp;
			if (entry.select(0).equals("*"))
				cmp = key.compareTo(entry.select(1));
			else
				cmp = key.compareTo(entry.min());

			if (entry.select(0).equals("*")){
			if (cmp < 0) {
				
				Page<K, Object> p = (Page<K, Object>) entry.get(entry.min());	
				p.entry.put(key, value);
			    enter((Page<K, V>) p);
				
			} else if (cmp > 0)
				entry.put(key, value);
			} else entry.put(key, value);
		}
	}

	void enter(Page<K, V> p) {
		entry.put(p.entry.min(), p);

	}

	boolean isExternal() {
		return this.botton == true;
	}

	boolean holds(K key) {
			return entry.contains(key);

	}

	@SuppressWarnings("unchecked")
	Page<K, Object> next(K key) {

		if(!isExternal()){
			
			if (entry.contains(key))
				return (Page<K, Object>) entry.get(key);
			else return next(entry.floor(key));
		} else return (Page<K, Object>) entry.get(key);

	}

	boolean hasOverflowed() {
	return entry.size() == M;

	}

	Page<K, Object> split() {
		Page<K, Object> p = new Page<>(isExternal());

			for (int j = entry.size()/2; j < entry.size(); j++) {
				p.insert(entry.select(j), entry.get(entry.select(j)));	
			}

			for (int j = entry.size()/2; j < entry.size(); j++) 
				entry.delete(entry.select(j));
             entry.delete(entry.select(entry.size()-1));

		return p;
	}

	Iterable<K> keys() {
		List<K> keys = new ArrayList<>();
			for (K e : entry.Keys())
				keys.add(e);
		return keys;
	}

	public static void main(String[] args) {
		Page<String, Object> root = new Page<>(true);
		Page<String, Object> sentinel = new Page<>(false);
		Page<String, Object> left;
		Page<String, Object> right;

		root.insert("*", sentinel);
		root.insert("K", 2);
		root.insert("X", 3);
		root.insert("C", 2);
		root.insert("T", 2);

		System.out.println("TAMANHO ATUAL, TRANSBORDOU?: " + root.hasOverflowed());
		
		System.out.println("ROOT ANTES DE DIVIDIR." + root.keys());
		left = root;
		right = root.split();
		root = new Page<>(false);
		root.enter(left);
		root.enter(right);
		System.out.println("LEFT" + left.keys());
		System.out.println("RIGHT" + right.keys());
		System.out.println("NOVO ROOT" + root.keys());
		
		Page<String, Object> p = new Page<>(false);
		p = root.next("C");
		System.out.println("FILHOS DE P" + p.keys());

	}
}
