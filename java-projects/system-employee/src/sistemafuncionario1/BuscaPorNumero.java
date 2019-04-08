/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package SistemaFuncionario1;

import javax.swing.JOptionPane;

/**
 *
 * @author Alan
 */
public class BuscaPorNumero {

    private Funcionario aux;
    
    public void BuscaPorNumero(double valor1, double valor2, Object vetor[], int tam) {
        int i;
        int cont = 0;
        double auxD;                    
        
        if (valor1 > valor2){
            auxD = valor1;
            valor1 = valor2;
            valor2 = auxD;
        }
        
        for (i = 0; i < tam; i++) {
            aux = (Funcionario) vetor[i];            
            if (aux.getSalario() >= valor1 && aux.getSalario() <= valor2) {
                System.out.println(vetor[i]);
                cont++;
            }
        }
        if (cont == 0) {         
            JOptionPane.showMessageDialog(null,"Nenhum Funcionario está com salário entre: " + valor1 + " e " + valor2, "Atenção", JOptionPane.WARNING_MESSAGE);
        }
    }
    
    //---------------------------------------------------------------
    
    public void BuscaPorNumeroAlternativo(double valor1, double valor2, Object vetor[], int tam) {
        
        int i;
        int cont = 0;
        double auxD;        
        /*
        Essa mudança foi para tira um do{}while da função principal que 
        com isso causa mais comodidade ao usuário. 
        porque fazer ele digitar os dois valores novamente
        se o sistema pode ajustar isso.
        */                 
        System.out.println("Valor1:"+valor1 +" e "+"valor2:"+valor2);
        if (valor1 > valor2){
            auxD = valor1;
            valor1 = valor2;
            valor2 = auxD;
        }        
        String acumuladora="";
        Funcionario aux;        
        for (i = 0; i < tam; i++) {
            aux = (Funcionario) vetor[i];            
            if (aux.getSalario() >= valor1 && aux.getSalario() <= valor2) {                
                acumuladora+=vetor[i]+"\n";                
                cont++;
            }
        }
        if (cont == 0) {            
            JOptionPane.showMessageDialog(null,"Nenhum Funcionario está com salario entre: " + valor1 + " e " + valor2, "Atenção", JOptionPane.WARNING_MESSAGE);
        }else{
        JOptionPane.showMessageDialog(null,acumuladora);
        }
        acumuladora="";
    }
}
