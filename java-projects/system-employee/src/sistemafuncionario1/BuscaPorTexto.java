package SistemaFuncionario1;

import javax.swing.JOptionPane;

/**
 *
 * @author Ualisson
 */
public class BuscaPorTexto {

   
    public boolean VerificaNome(String nome1, String nome2) {
        int percorrer;
        
        if (nome1.length() < nome2.length()){
            percorrer = nome1.length();
        } else if (nome2.length() < nome1.length()) {
            percorrer = nome2.length();
        } else {
            percorrer = nome1.length();
        }
        
        
        for (int i = 0; i < percorrer; i++) {
            if (nome1.charAt(i) != nome2.charAt(i)) {
                return false;
            }
            
            if (i == percorrer * 0.4) {                
                return true;
            }
        }
        return true;
    }

    public void BuscaPorTexto(String nome, Object vetor[], int tam) {
        int j;
        int cont = 0;
        Funcionario aux;
        for (j = 0; j < tam; j++) {
            aux = (Funcionario) vetor[j];
            if (VerificaNome(nome, aux.getNome()) || VerificaNome(nome, aux.getCpf())) {
                System.out.println(vetor[j]);
                cont++;
            }
        }        
        if (cont == 0) {
            JOptionPane.showMessageDialog(null,"Nenhum Funcionário com esse seguinte nome ou CPF: " + nome,"Atenção !", JOptionPane.WARNING_MESSAGE);
            //System.out.println("Nenhum Funcionário com esse seguinte nome ou CPF: " + nome);
        }
    }        
    //------------------------------------------------
    
    
    public boolean VerificaNomeAlternativo(String nome1, String nome2) {
        int percorrer;
        if (nome1.length() < nome2.length()){
            percorrer = nome1.length();
        } else if (nome2.length() < nome1.length()) {
            percorrer = nome2.length();
        } else {
            percorrer = nome1.length();
        }
        
        for (int i = 0; i < percorrer; i++) {
            if (nome1.charAt(i) != nome2.charAt(i)) {
                return false;
            }
            /*
            Alteração que fiz foi seguinte quando percorrer atingir 40% de sua busca 
            com sucesso então tem grande chances de ser o que o cliente esta pesquisando
            então ele vai listar todos os que forem semelhantes com 40%.
            */
            if (i == percorrer * 0.4) {                
                return true;
            }
        }
        return true;
    }

    public void BuscaPorTextoAlternativo(String nome, Object vetor[], int tam) {
        int j;
        int cont = 0;
        Funcionario aux;
        String acumuladora="";
        for (j = 0; j < tam; j++) {
            aux = (Funcionario) vetor[j];
            if (VerificaNomeAlternativo(nome, aux.getNome()) || VerificaNomeAlternativo(nome, aux.getCpf())) {
                acumuladora+=vetor[j]+"\n";                
                //System.out.println(vetor[j]);
                cont++;
            }
        }
        JOptionPane.showMessageDialog(null,acumuladora);
        acumuladora="";
        if (cont == 0) {
            JOptionPane.showMessageDialog(null,"Nenhum Funcionário com esse seguinte nome ou CPF: " + nome,"Atenção !", JOptionPane.WARNING_MESSAGE);
            //System.out.println("Nenhum Funcionário com esse seguinte nome ou CPF: " + nome);
        }
    }        
}
