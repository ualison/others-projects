package SistemaFuncionario1;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Random;
import java.util.Scanner;


/**
 *
 * @author Bruno
 */

public class FuncExtras {

    public static void Menu(int tam, String texto) {
        System.out.println("|--------------------------------------------|");
        System.out.println("|Sistema de Cadastro de Funcionario          |");
        System.out.println("|--------------------------------------------|");
        System.out.println("  Total de Funcionario: " + tam + " Olá, " + texto);
        System.out.println("|--------------------------------------------|");
        System.out.println("|----------MENU PRINCIPAL--------------------|");
        System.out.println("| 1 - Cadastrar Funcionário                  |");
        System.out.println("| 2 - SubMenu Buscar                         |");
        System.out.println("| 3 - SubMenu Imprimir                       |");
        System.out.println("| 4 - Remover                                |");
        System.out.println("| 5 - Fechar                                 |");
        System.out.println("|____________________________________________|");
        System.out.print("|OPÇÃO: ");
    }

    public static void SubMenuImprimir() {
        System.out.println("|--------------------SUBMENU IMPRIMIR------------------------|");
        System.out.println("| 1 - Imprimir todos os Funcionários                         |");
        System.out.println("| 2 - Imprimir todos os Funcionários em ordem Alfabética     |");
        System.out.println("| 3 - Imprimir o Funcionário com maior salário               |");
        System.out.println("| 4 - Imprimir o Funcionário mais velho dentro da empresa    |");
        System.out.println("| 5 - Imprimir Funcionários com apenas(Nome,Cargo e Salário) |");
        System.out.println("| 6 - Imprimir o Funcionários mais novo dentro da empresa    |");
        System.out.println("| 7 - Gasto Total com a Folha de Pagamento                   |");
        System.out.println("| 8 - Percorrer Tabela                                       |");
        System.out.println("| 9 - <¬ VOLTAR                                              |");
        System.out.println("|____________________________________________________________|");
        System.out.print("|OPÇÃO: ");
    }

    public static void SubMenuBuscar() {
        System.out.println("|--------------------SUBMENU BUSCAR-----------------------|");
        System.out.println("| 1 - Buscar por Texto (Nome ou CPF)                      |");
        System.out.println("| 2 - Buscar por Número (Salário)                         |");
        System.out.println("| 3 - Buscar por Data (Data nascimento ou Data Admissão)  |");
        System.out.println("| 4 - <¬ VOLTAR                                           |");
        System.out.println("|_________________________________________________________|");
        System.out.print("|OPÇÃO: ");
    }

    public static void AndarTabela() {
        System.out.println("|----------SUBMENU PERCORRER TABELA-----------|");
        System.out.println("| 1 - Primeiro                                |");
        System.out.println("| 2 - Próximo                                 |");
        System.out.println("| 3 - Anterior                                |");
        System.out.println("| 4 - Ultimo                                  |");
        System.out.println("| 5 - <¬ VOLTAR                               |");
        System.out.println("|_____________________________________________|");
        System.out.print("|OPÇÃO: ");
    }

    public static double GeraGastoComFuncionarios(Object vetor[], int tam) {
        double Total = 0.0;
        Funcionario aux;
        for (int i = 0; i < tam; i++) {
            aux = (Funcionario) vetor[i];
            Total += aux.getSalario();
        }
        return Total;

    }

    public static void ultimo(Object vetor[], int tam, int atual) {
        Funcionario aux;
        if (atual == tam) {
            System.out.println("Já está no ultimo Funcionário");
            ultimo(vetor, tam, atual - 1);
        } else {
            aux = (Funcionario) vetor[tam - 1];
            System.out.println(aux.toString());
        }
    }

    public static void primeiro(Object vetor[], int tam, int atual) {
        Funcionario aux;
        if (atual == 0) {
            System.out.println("Você já está no primeiro Funcionário");
        } else {
            aux = (Funcionario) vetor[0];
            System.out.println(aux.toString());
        }
    }

    public static void proximo(Object vetor[], int tam, int atual) {
        Funcionario aux;
        if (atual == tam - 1) {
            System.out.println("você chegou ao ultimo Funcionário da tabela.!");
            ultimo(vetor, tam, atual);
        } else {
            aux = (Funcionario) vetor[atual + 1];
            System.out.println(aux.toString());
        }
    }

    public static void anterior(Object vetor[], int atual) {
        Funcionario aux;
        if (atual == 0) {
            System.out.println("você já chegou ao primeiro Funcionário.!");
            primeiro(vetor, atual, atual);
        } else if (atual == -1) {
            primeiro(vetor, atual, atual);
        } else {
            aux = (Funcionario) vetor[atual - 1];
            System.out.println(aux.toString());
        }
    }

    public static void Informativo(Object array[], int tam) {
        if (tam == array.length - 5) {
            System.out.println("O limite para cadastro de funcionário está prestes a ser atingido. \n");
            System.out.println(" - Limite de funcionários é de: " + array.length);
            System.out.println(" - Quantidade atual: " + tam);
            System.out.println(" - Quantidade restante: " + (array.length - tam) + "\n");
        }
    }

    static boolean isDigit(String s) {
        return s.matches("[0-9]*");
    }

    public static void LimparTela() {
        for (int i = 0; i < 1; i++) {
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
        }
    }

    public static void SubMenus(String texto) {
        System.out.println("|" + texto + "| \n");
    }

    public static int VerificaData(String data) {
        SimpleDateFormat df = new SimpleDateFormat("dd/MM/yyyy");
        df.setLenient(false);
        try {
            df.parse(data);
        } catch (ParseException ex) {
            return 0; // FALSE
        }
        return 1; // TRUE
    }

    public static int Pergunta(String texto, int n1, int n2) {
        String op;
        int cont = 0;
        int opp = 0;
        Scanner ler = new Scanner(System.in);
        System.out.println(texto);
        do {
            op = ler.nextLine();

            try {
                opp = Integer.parseInt(op);
                cont = 0;
            } catch (Exception x) {
                cont++;
            }

            if (!isDigit(op) || cont != 0) {
                System.out.println("Ops! Digite uma opção valida " + n1 + " até/ou " + n2);
            }
        } while (!isDigit(op) || cont != 0);
        return opp;
    }

    public static String CaptHora() {
        Calendar c1 = Calendar.getInstance();
        int hora = c1.get(Calendar.HOUR_OF_DAY);
        if (hora <= 12) {
            return "Bom dia";
        } else if (hora > 12 && hora < 18) {
            return "Boa tarde";
        } else if (hora > 18 && hora < 23) {
            return "Boa Noite";
        } else {
            return "Boa Madrugada";
        }
    }

    public static int GeraSalarioSo(Object vetor[], int tam, int vez) {
        Random r = new Random();
        double Gvalor = GeraGastoComFuncionarios(vetor, tam);
        int valor, usado;
        if (vez == 1) {
            usado = (int) (Gvalor / tam);
        } else {
            usado = (int) (Gvalor);
        }
        do {
            valor = r.nextInt(usado);
        } while (valor <= 0);

        return valor;
    }

    public static String DataAleatoriamente(int vez) {
        Date atual = new Date();
        SimpleDateFormat Formatar = new SimpleDateFormat("dd/MM/yyyy");
        if (vez == 2) {
            return Formatar.format(atual);
        } else {
            Random gerar = new Random();
            Calendar pos = Calendar.getInstance();
            pos.setTime(atual);
            pos.add(Calendar.MONTH, -gerar.nextInt(10));
            pos.add(Calendar.YEAR, -gerar.nextInt(30));
            pos.add(Calendar.DAY_OF_MONTH, -gerar.nextInt(12));
            return Formatar.format(pos.getTime());
        }
    }

    public static int VerificaDouble(String salario) {
        salario = salario.replace(",", ".");
        double valor;
        int cont;
        try {
            valor = Double.parseDouble(salario);
            cont = 0;
        } catch (NumberFormatException e) {
            cont = 1;
        }
        return cont;
    }

    public static int VerificarDatas(String data, int vez) throws ParseException {
        DateFormat Formatar1 = DateFormat.getDateInstance();        
        Date DataAtual = new Date();
        int valor;
        
        int dia, mes, ano;        
        if (vez == 1){
            valor = 18;
        } else {
            valor = 0;
        }
        
        Calendar modifica = Calendar.getInstance();
        modifica.setTime(DataAtual);        
        dia = modifica.get(Calendar.DAY_OF_MONTH);
        ano = modifica.get(Calendar.YEAR);
        mes = modifica.get(Calendar.MONTH);                
        ano-=valor;
        modifica.set(ano, mes, dia);
        DataAtual = modifica.getTime();
        
        return DataAtual.compareTo(Formatar1.parse(data));
   
        /*
        data atual e maior retorna 1;
        as datas são igual =0;
        data atual e menor =-1
        */
    }           
}
