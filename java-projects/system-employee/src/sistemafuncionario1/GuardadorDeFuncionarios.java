package SistemaFuncionario1;


import javax.swing.JOptionPane;

/**
 *
 * @author Bruno
 */

public class GuardadorDeFuncionarios extends GuardadorDeObjetos {

    public GuardadorDeFuncionarios() {
        super(100);
    }

    @Override
    public Object getObjeto(int indice) {
        if (indice >= this.arrayDeObjetos.length) {
        }
        return this.arrayDeObjetos[indice];
    }

    public void aumentarTamanhoDoConjunto(int n){

        Object[] aux = new Object[n];
        System.arraycopy(this.arrayDeObjetos, 0, aux, 0, this.arrayDeObjetos.length);
        this.arrayDeObjetos = aux;
    }

    @Override
    public void addObjeto(Object object) {                                                                                                                                    
        if (this.posicao > this.arrayDeObjetos.length-3){
            //Você atingiu 95% da capacidade de armazenamento do seu Banco de Dados
            JOptionPane.showMessageDialog(null,"Você atingiu 95% da capacidade de armazenamento do seu Banco de Dados, mas não se preocupe o problema já foi resolvido \n continue usufruindo do sistema","Ops!",JOptionPane.WARNING_MESSAGE);
            aumentarTamanhoDoConjunto((int) (this.arrayDeObjetos.length * 0.8));
        }                         
        this.arrayDeObjetos[this.posicao] = object;
        this.posicao++;
    }

    @Override
    public Object[] getListaDeObjetos() {
        return this.arrayDeObjetos;
    }

    @Override
    public int getTamanhoListaDeObjetos() {
        return this.arrayDeObjetos.length;
    }

    public void Remover(int posi) {
        Funcionario aux;        
        for (int i = posi; i < this.posicao - 1; i++) {
            aux = (Funcionario) this.arrayDeObjetos[i + 1];
            this.arrayDeObjetos[i] = aux;
        }
        this.posicao--;
    }

    public boolean VerificaFuncionarioNome(String nome) {
        Funcionario aux;
        for (int i = 0; i < this.posicao; i++) {
            aux = (Funcionario) this.arrayDeObjetos[i];
            if (aux.getNome().equals(nome)) {
                return true;
            }
        }
        return false;
    }

    public int VerificaFuncionarioCPF(String CPF) {
        Funcionario aux;
        for (int i = 0; i < this.posicao; i++) {
            aux = (Funcionario) this.arrayDeObjetos[i];
            if (aux.getCpf().equals(CPF)) {
                return i; // AQUI IGUAL A TRUE                
            }
        }
        return -1; // FALSE        
    }

}
