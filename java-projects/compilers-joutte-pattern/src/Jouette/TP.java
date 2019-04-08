package Jouette;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Stack;

public class TP {

	Stack<String> padraoValues = new Stack<String>();
	HashMap<String, String> consts = new HashMap<String, String>();
	HashMap<String, String> temps = new HashMap<String, String>();

	class Node {

		private static final int IDENTAÇÃO = 3;

		String data;
		Node left, right;
		boolean coberto = false;
		int id = 0;

		public void indent(StringBuilder builder, int indent) {
			builder.append(repeat(indent * (IDENTAÇÃO + 1), " "));
		}

		public void novaLinha(StringBuilder builder) {
			builder.append(System.lineSeparator());
		}

		public String repeat(int quantidade, String valor) {
			return new String(new char[quantidade]).replace("\0", valor);
		}

		public String toString(int identacao) {
			StringBuilder builder = new StringBuilder();

			if (consts.containsKey(data))
				builder.append(consts.get(data));
			else if (temps.containsKey(data))
				builder.append(temps.get(data));
			else if (data.contains("$"))
				builder.append("MOVE");
			else if (data.contains("%"))
				builder.append("MEM");
			else
				builder.append(data);

			novaLinha(builder);
			if (left != null) {
				indent(builder, identacao);
				builder.append("└" + repeat(IDENTAÇÃO, "─") + left.toString(identacao + 1));
			}
			if (right != null) {
				indent(builder, identacao);
				builder.append("└" + repeat(IDENTAÇÃO, "─") + right.toString(identacao + 1));
			}
			return builder.toString();
		}

		@Override
		public String toString() {
			return toString(0);
		}

		public boolean isCoberto() {
			return coberto;
		}

		public void setCoberto(boolean coberto) {
			this.coberto = coberto;
		}
	};

	public Node criarNode(String data, int id) {
		Node node = new Node();
		node.data = data;
		node.left = node.right = null;
		node.id = id;
		return node;
	}

	public void preOrder(Node node) {

		if (node == null)
			return;
		System.out.println(node.data);
		preOrder(node.left);
		preOrder(node.right);
	}

	public int encontrarIndice(String str1, int a, int b) {

		if (a > b)
			return -1;

		Stack<Character> s = new Stack<Character>();

		char[] str = str1.toCharArray();

		for (int i = a; i <= b; i++) {
			if (str[i] == '(')
				s.push(str[i]);
			else if (str[i] == ')') {
				int n = s.size();
				if (s.peek() == '(') {
					s.pop();
					if (s.empty())
						return i;
				}
			}
		}
		return -1;
	}

	public Node criarArvore(String str1, int a, int b, int c) {

		if (a > b)
			return null;

		char[] str = str1.toCharArray();
		char w = str[a];
		Node root = criarNode(String.valueOf(w), c);

		int indice = -1;

		if (a + 1 <= b && str[a + 1] == '(')
			indice = encontrarIndice(str1, a + 1, b);

		if (indice != -1) {
			root.left = criarArvore(str1, a + 2, indice - 1, c);
			c++;
			root.right = criarArvore(str1, indice + 2, b - 1, c);
		}
		return root;
	}

	public String tratarExpressao(String expr) {

		String str = expr.replace("MOVE", "$");
		String str2 = str.replace("MEM", "%");
		String str3 = str2.replace(",", ")(");
		String str4 = str3.replace(" ", "");

		String str5 = str3.replace("(", " ");
		String str6 = str5.replace(")", " ");
		String str7 = str6.replace("  ", " ");

		String[] strv = str7.split(" ");

		for (int i = 0; i < strv.length; i++) {
			CharSequence c = "CONST";
			if (strv[i].contains(c)) {
				consts.put(strv[i + 1], "CONST " + strv[i + 1]);
			}
			CharSequence t = "TEMP";
			if (strv[i].contains(t)) {
				char[] s = strv[i + 1].toCharArray();
				temps.put(String.valueOf(s[0]), "TEMP " + strv[i + 1]);
			}
		}

		String str8 = str4.replace("CONST", "");
		String str9 = str8.replace("TEMP", "");

		return str9;
	}

	public void selecaoGuloso(Node root) {
		if (root != null) {

			if (root.data.equals("$") && root.coberto == false)
				if (root.left != null && root.right != null)
					if (root.left.data.equals("%") && root.right.data.equals("2")) {

						root.setCoberto(true);
						root.left.setCoberto(true);
						root.right.setCoberto(true);
						String s = "MOVEM: " + "M[r" + root.left.id + "] + M[r" + root.right.id + "]";
						padraoValues.push(s);
					}

			if (root.data.equals("$") && root.isCoberto() == false)
				if (root.left != null)
					if (root.left.data.equals("%"))
						if (root.left.left != null)
							if (root.left.left.data.equals("+"))
								if (root.left.left.right != null)
									if (consts.containsKey(root.left.left.right.data)) {

										root.setCoberto(true);
										root.left.setCoberto(true);
										root.left.left.setCoberto(true);
										root.left.left.right.setCoberto(true);
										String s = "STORE" + "M[r" + root.left.left.right.id + " + "
												+ root.left.left.left.data.substring(6) + "] " + " <- r"
												+ root.right.id;
										padraoValues.push(s);
									}

			if (root.data.equals("$") && root.isCoberto() == false)
				if (root.left != null)
					if (root.left.data.equals("%"))
						if (root.left.left != null)
							if (root.left.left.data.equals("+"))
								if (root.left.left.left != null)
									if (consts.containsKey(root.left.left.left.data)) {

										root.setCoberto(true);
										root.left.setCoberto(true);
										root.left.left.setCoberto(true);
										root.left.left.left.setCoberto(true);
										String s = "STORE" + "M[r" + root.left.left.right.id + " + "
												+ root.left.left.left.data.substring(6) + "] " + " <- r"
												+ root.right.id;
										padraoValues.push(s);
									}

			if (root.data.equals("$") && root.isCoberto() == false)
				if (root.left != null)
					if (root.left.data.equals("%"))
						if (root.left.left != null)
							if (consts.containsKey(root.left.left.data)) {

								root.setCoberto(true);
								root.left.setCoberto(true);
								root.left.left.setCoberto(true);
								String s = "STORE" + "M[r" + root.left.right.id + " + "
										+ consts.get(root.left.left.data).substring(6) + "] " + " <- r" + root.right.id;
								padraoValues.push(s);
							}

			if (root.data.equals("$") && root.isCoberto() == false)
				if (root.left != null)
					if (root.left.data.equals("%")) {

						root.setCoberto(true);
						root.left.setCoberto(true);
						String s = "STORE: " + "M[r" + root.left.left.id + " + " + "r0" + "] " + " <- r"
								+ root.right.id;
						padraoValues.push(s);
					}

			if (root.data.equals("%") && root.isCoberto() == false)
				if (root.left != null)
					if (root.left.data.equals("+"))
						if (root.left.right != null)
							if (consts.containsKey(root.left.right.data)) {

								root.setCoberto(true);
								root.left.setCoberto(true);
								root.left.right.setCoberto(true);
								String s = "LOAD: " + "r" + root.id + " <- M["
										+ temps.get(root.left.left.data).substring(5) + " + "
										+ consts.get(root.left.right.data).substring(6) + "]";
								padraoValues.push(s);
							}

			if (root.data.equals("%") && root.isCoberto() == false)
				if (root.left != null)
					if (root.left.data.equals("+"))
						if (root.left.left != null)
							if (consts.containsKey(root.left.left.data)) {

								root.setCoberto(true);
								root.left.setCoberto(true);
								root.left.left.setCoberto(true);
								String s = "LOAD: " + "r" + root.id + " <- M["
										+ temps.get(root.left.right.data).substring(6) + " + "
										+ consts.get(root.left.left.data).substring(6) + "]";
								padraoValues.push(s);
							}

			if (root.data.equals("%") && root.isCoberto() == false)
				if (root.left != null)
					if (consts.containsKey(root.left.data)) {

						root.setCoberto(true);
						root.left.setCoberto(true);
						String s = "LOAD: " + "r" + root.id + " <- M[ r0" + " + "
								+ consts.get(root.left.data).substring(6) + "]";
						padraoValues.push(s);
					}

			if (root.data.equals("%") && root.isCoberto() == false) {

				root.setCoberto(true);
				String s = "LOAD: " + "r" + root.id + " <- M[ r" + root.left.id + " + " + "r0" + "]";
				padraoValues.push(s);
			}

			if (root.data.equals("-") && root.isCoberto() == false)
				if (root.right != null)
					if (consts.containsKey(root.right.data)) {

						root.setCoberto(true);
						root.right.setCoberto(true);
						String s = "SUBI: " + "r" + root.id + " <- r" + root.left.id + " - r" + root.right.id;
						padraoValues.push(s);
					}
			if (root.data.equals("-") && root.isCoberto() == false) {

				root.setCoberto(true);
				String s = "SUB: " + "r" + root.id + " <- r" + root.left.id + " - r" + root.right.id;
				padraoValues.push(s);
			}

			if (root.data.equals("+") && root.isCoberto() == false)
				if (root.right != null)
					if (consts.containsKey(root.right.data)) {

						root.setCoberto(true);
						root.right.setCoberto(true);
						String s = "ADDI: " + "r" + root.id + " <- r0 " + "+ r" + root.right.id;
						padraoValues.push(s);
					}

			if (root.data.equals("+") && root.isCoberto() == false)
				if (root.left != null)
					if (consts.containsKey(root.left.data)) {

						root.setCoberto(true);
						root.left.setCoberto(true);
						String s = "ADDI: " + "r" + root.id + " <-" + " + r" + root.left.id + " + " + "r0";
						padraoValues.push(s);
					}

			if (consts.containsKey(root.data) && root.isCoberto() == false) {
				List<String> a = new ArrayList<String>();

				root.setCoberto(true);
				String s = "ADDI: " + "r" + root.id + " <- r0" + " + " + consts.get(root.data).substring(6);
				padraoValues.push(s);
			}

			if (root.data.equals("+") && root.isCoberto() == false) {

				root.setCoberto(true);
				String s = "ADD: " + "r" + root.id + " <- r" + root.left.id + " + r" + root.right.id;
				padraoValues.push(s);
			}

			if (root.data.equals("/") && root.isCoberto() == false) {
				List<String> a = new ArrayList<String>();
				a.add(root.data);

				root.setCoberto(true);
				String s = "DIV: " + "r" + root.id + " <- r" + root.left.id + " / r" + root.right.id;
				padraoValues.push(s);
			}

			if (root.data.equals("*") && root.isCoberto() == false) {

				root.setCoberto(true);
				String s = "MUL: " + "r" + root.id + " <- r" + temps.get(root.left.data).substring(5) + " * r"
						+ root.right.id;
				padraoValues.push(s);
			}
			selecaoGuloso(root.right);
			selecaoGuloso(root.left);
		}
	}

	public static void main(String[] args) {

		String L = "MOVE(MEM(+(MEM( +( TEMP fp,CONST a)),*(TEMP i,CONST 4))),MEM(+(TEMP FP,CONST x)))";
		String L2 = "MOVE( MEM( +( +( CONST 1000, MEM( TEMP x)), TEMP fp)), CONST 0)";
		String L3 = "MOVE( MEM( +( MEM( +( TEMP fp, CONST 8)), *( TEMP i,CONST 4))),+(MEM ( +( TEMP FP, CONST 6)), CONST 7))";

		TP tp1 = new TP();
		TP tp2 = new TP();
		TP tp3 = new TP();

		String TreeL = tp1.tratarExpressao(L);
		String TreeL2 = tp2.tratarExpressao(L2);
		String TreeL3 = tp3.tratarExpressao(L3);

		Node rootL = tp1.criarArvore(TreeL, 0, TreeL.length() - 1, 1);
		Node rootL2 = tp2.criarArvore(TreeL2, 0, TreeL2.length() - 1, 1);
		Node rootL3 = tp3.criarArvore(TreeL3, 0, TreeL3.length() - 1, 1);

		System.out.println("\nÁRVORE DA EXPRESSÃO L:");
		System.out.println(rootL.toString());
		System.out.println("SELEÇÃO GULOSO L:");
		tp1.selecaoGuloso(rootL);
		while (!tp1.padraoValues.empty()) {
			String p = tp1.padraoValues.pop();
			System.out.println(p);
		}

		System.out.println("\nÁRVORE DA EXPRESSÃO L2:");
		System.out.println(rootL2.toString());
		System.out.println("SELEÇÃO GULOSO L2:");
		tp2.selecaoGuloso(rootL2);
		
		while (!tp2.padraoValues.empty()) {
			String p = tp2.padraoValues.pop();
			System.out.println(p);
		}

		System.out.println("\nÁRVORE DA EXPRESSÃO L3:");
		System.out.println(rootL3.toString());
		System.out.println("SELEÇÃO GULOSO L3:");
		tp3.selecaoGuloso(rootL3);
		while (!tp3.padraoValues.empty()) {
			String p = tp3.padraoValues.pop();
			System.out.println(p);
		}

	}
}
