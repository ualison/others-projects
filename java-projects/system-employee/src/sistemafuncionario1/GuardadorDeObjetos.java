package SistemaFuncionario1;

/**
 *
 * @author Bruno
 */

abstract class GuardadorDeObjetos {

    public Object[] arrayDeObjetos;

    public int posicao = 0;
        
    public GuardadorDeObjetos() {
        this.arrayDeObjetos = new Object[100];
    }

    public GuardadorDeObjetos(Object objs[]) {
        this.arrayDeObjetos = objs;
    }

    public GuardadorDeObjetos(int n){
        if (n < 0) {
//                throw new ExceptionC();
        }

        this.arrayDeObjetos = new Object[n];
    }

    public abstract Object getObjeto(int indice);

    public abstract void aumentarTamanhoDoConjunto(int n);

    public abstract void addObjeto(Object object);

    public abstract Object[] getListaDeObjetos();

    public abstract int getTamanhoListaDeObjetos();
    
    public abstract  void Remover(int posi);
    
    public abstract boolean VerificaFuncionarioNome(String nome);
    
    public abstract int VerificaFuncionarioCPF(String CPF);            

}
