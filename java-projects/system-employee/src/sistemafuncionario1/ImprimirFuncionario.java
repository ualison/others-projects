package SistemaFuncionario1;

import com.itextpdf.text.DocumentException;
import com.itextpdf.text.PageSize;
import com.itextpdf.text.Paragraph;
import com.itextpdf.text.pdf.PdfPCell;
import com.itextpdf.text.pdf.PdfPTable;
import com.itextpdf.text.pdf.PdfWriter;

import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Collections;
import java.util.Date;
import java.util.List;
import javax.swing.JOptionPane;

/**
 *
 * @author Bruno
 */
public class ImprimirFuncionario {

    private String Acumula;

    public void Impirmir3Campos(Object vetor[], int tam) {
        Funcionario aux;
        for (int i = 0; i < tam; i++) {
            aux = (Funcionario) vetor[i];
            System.out.println("| Nome :" + aux.getNome() + "| Cargo: " + aux.getCargoOcupa()
                    + "| Salário: " + aux.getSalario());
        }
    }

    /*
     Ira imprimir os dados do Funcionario que tiver maior salário dentro da Empresa
     */
    public void ImpirmirFuncionarioComMaiorSalario(Object vetor[], int tam) {
        int pos = 0;
        Funcionario aux;
        aux = (Funcionario) vetor[0];
        double temp = aux.getSalario();
        for (int i = 1; i < tam; i++) {
            aux = (Funcionario) vetor[i];
            if (aux.getSalario() > temp) {
                temp = aux.getSalario();
                pos = i;
            }
        }
        System.out.println(vetor[pos]);
    }

    /*       
     Método para imprimir todos os Funcionarios e seus respectivos dados    
     */
    public void ImprimirTudo(Object vetor[], int tam) {
        for (int i = 0; i < tam; i++) {
            System.out.println(vetor[i]);
        }
    }
    /*
     Metodo alternativo.
     */

    public void Ordenar(Object vetor[], int tam) {

        List<Funcionario> funcionario = new ArrayList<>();
        Funcionario aux;

        for (int i = 0; i < tam; i++) {
            aux = (Funcionario) vetor[i];
            funcionario.add(aux);
        }
        Collections.sort(funcionario);
        for (Funcionario elementos : funcionario) {
            System.out.println(elementos);
        }
    }

    public List<Funcionario> ImprimirTodosOrdenados(Object vetor[], int tam) {
        List<Funcionario> funcionario = new ArrayList<>();
        Funcionario aux;
        for (int i = 0; i < tam; i++) {
            aux = (Funcionario) vetor[i];
            funcionario.add(aux);
        }
        return funcionario;
    }
    /*
     Método Ira imprimir o Funcionario mais novo da Empresa em relação quantidade de  aniversarios.
     */

    public void ImprimirFuncionarioMaisNovoAlt(Object vetor[], int tam) {
        int j;
        Date auxAnos;
        Funcionario aux;
        Funcionario temp = (Funcionario) vetor[0];

        for (j = 0; j < tam; j++) {
            aux = (Funcionario) vetor[j];
            if (temp.getDataNascimento().compareTo(aux.getDataNascimento()) == 1) {
                temp = aux;
            }
        }
        System.out.println(temp);

    }

    public void ImprimirFuncionarioComMaisTempoNaEmpresa(Object vetor[], int tam) {
        Funcionario aux;
        Funcionario temp = (Funcionario) vetor[0];
        for (int j = 0; j < tam; j++) {
            aux = (Funcionario) vetor[j];
            if (temp.getDataAdmissao().compareTo(aux.getDataAdmissao()) == 1) {
                temp = aux;
            }
        }
        JOptionPane.showMessageDialog(null, temp);
    }

    public void ImprimirAniversariantesDoDia(Object vetor[], int tam) {
        Funcionario aux;
        Date atual = new Date();
        int qntAnos;
        DateFormat formatar = DateFormat.getDateInstance();
        Calendar auxAtual = Calendar.getInstance();
        Calendar auxAniversario = Calendar.getInstance();
        auxAtual.setTime(atual);
        String armazena = "";
        for (int i = 0; i < tam; i++) {
            aux = (Funcionario) vetor[i];
            auxAniversario.setTime(aux.getDataNascimento());
            if (auxAtual.get(Calendar.DAY_OF_MONTH) == auxAniversario.get(Calendar.DAY_OF_MONTH) && auxAtual.get(Calendar.MONTH) == auxAniversario.get(Calendar.MONTH)) {
                qntAnos = auxAtual.get(Calendar.YEAR) - auxAniversario.get(Calendar.YEAR);
                armazena += aux.getNome() + ", " + qntAnos + " anos" + "\n";
            }
        }
        JOptionPane.showMessageDialog(null, armazena, "Aniversariantes do Dia", JOptionPane.WARNING_MESSAGE);
    }

    //FUNÇÕES ALTERNATIVAS !
    public void Impirmir3CamposAlternativo(Object vetor[], int tam) {
        Funcionario aux;

        for (int i = 0; i < tam; i++) {
            aux = (Funcionario) vetor[i];

            Acumula += "|Nome :" + aux.getNome() + " |Cargo: " + aux.getCargoOcupa()
                    + " |Salário: " + aux.getSalario() + "\n";
        }
        JOptionPane.showMessageDialog(null, Acumula);
        Acumula = "";
    }

    /*
     Ira imprimir os dados do Funcionario que tiver maior salário dentro da Empresa
     */
    public void ImpirmirFuncionarioComMaiorSalarioAlternativo(Object vetor[], int tam) {
        int pos = 0;
        Funcionario aux;
        aux = (Funcionario) vetor[0];
        double temp = aux.getSalario();
        for (int i = 1; i < tam; i++) {
            aux = (Funcionario) vetor[i];
            if (aux.getSalario() > temp) {
                temp = aux.getSalario();
                pos = i;
            }
        }
        JOptionPane.showMessageDialog(null, vetor[pos].toString());
    }

    /*       
     Método para imprimir todos os Funcionarios e seus respectivos dados    
     */
    public void ImprimirTudoAlternativo(Object vetor[], int tam) {
        for (int i = 0; i < tam; i++) {
            Acumula += vetor[i] + " \n";
        }
        JOptionPane.showMessageDialog(null, Acumula, "Todos os Funcionários Cadastrados", JOptionPane.WARNING_MESSAGE);
        Acumula = "";
    }
    /*
     Metodo alternativo.
     */

    public void OrdenarAlternativo(Object vetor[], int tam) {

        List<Funcionario> funcionario = new ArrayList<>();
        Funcionario aux;

        for (int i = 0; i < tam; i++) {
            aux = (Funcionario) vetor[i];
            funcionario.add(aux);
        }
        Collections.sort(funcionario);
        for (Funcionario elementos : funcionario) {
            Acumula += elementos + "\n";
            //System.out.println(elementos);
        }
        JOptionPane.showMessageDialog(null, Acumula, "Todos os Funcionários em Ordem Alfabética", JOptionPane.WARNING_MESSAGE);
        Acumula = "";
    }

    /*
     Método Ira imprimir o Funcionario mais novo da Empresa
     */
    public void ImprimirFuncionarioMaisNovoAlternativo(Object vetor[], int tam) {
        int j;
        Date auxAnos;
        Funcionario aux;
        Funcionario temp = (Funcionario) vetor[0];

        for (j = 0; j < tam; j++) {
            aux = (Funcionario) vetor[j];
            if (temp.getDataNascimento().compareTo(aux.getDataNascimento()) == 1) {
                temp = aux;
            }
        }
        JOptionPane.showMessageDialog(null, temp, "Funcionário Mais novo da empresa", JOptionPane.WARNING_MESSAGE);
        Acumula = "";
    }

    public void ImprimirFuncionarioComMaisTempoNaEmpresaAlternativo(Object vetor[], int tam) {
        Funcionario aux;
        Date auxAnos;
        Funcionario temp = (Funcionario) vetor[0];
        for (int j = 0; j < tam; j++) {
            aux = (Funcionario) vetor[j];
            if (temp.getDataAdmissao().compareTo(aux.getDataAdmissao()) == 1) {
                temp = aux;
            }
        }
        JOptionPane.showMessageDialog(null, temp, "Funcionário com mais tempo dentro da empresa", JOptionPane.WARNING_MESSAGE);
        Acumula = "";
    }

    public void ImprimirAniversariantesDoMesAlternativo(Object vetor[], int tam) {
        Funcionario aux;
        int cont = 0;
        Date atual = new Date();
        int qntAnos;
        DateFormat formatar = DateFormat.getDateInstance();
        Calendar auxAtual = Calendar.getInstance();
        Calendar auxAniversario = Calendar.getInstance();
        auxAtual.setTime(atual);
        for (int i = 0; i < tam; i++) {
            aux = (Funcionario) vetor[i];
            auxAniversario.setTime(aux.getDataNascimento());
            if (auxAtual.get(Calendar.DAY_OF_MONTH) == auxAniversario.get(Calendar.DAY_OF_MONTH) && auxAtual.get(Calendar.MONTH) == auxAniversario.get(Calendar.MONTH)) {
                qntAnos = auxAtual.get(Calendar.YEAR) - auxAniversario.get(Calendar.YEAR);
                Acumula += aux.getNome() + ", " + qntAnos + " anos" + "\n";
                cont++;

            }
        }
        if (cont >= 1) {
            JOptionPane.showMessageDialog(null, Acumula, "Aniversariantes do Dia", JOptionPane.WARNING_MESSAGE);
        }
        Acumula = "";
    }

    public void GeraPDF(Object vetor[], int tam) {
        com.itextpdf.text.Document document = new com.itextpdf.text.Document();
        int i;
        DateFormat formatar = DateFormat.getDateInstance();

        Funcionario cls[] = new Funcionario[tam];
        for (int j = 0; j < tam; j++) {
            cls[j] = (Funcionario) vetor[j];
        }
        try {
            PdfWriter.getInstance(document, new FileOutputStream("arquivo.pdf"));
            document.open();
            document.setPageSize(PageSize.A10);
            int numeroDeColunas = 5;
            PdfPTable table = new PdfPTable(numeroDeColunas);
            table.addCell(new PdfPCell(new Paragraph("Nome")));
            table.addCell(new PdfPCell(new Paragraph("CPF")));
            table.addCell(new PdfPCell(new Paragraph("Data de Nascimento")));
            table.addCell(new PdfPCell(new Paragraph("Cargo Ocupado")));
            table.addCell(new PdfPCell(new Paragraph("Salário")));
            
            for (i = 0; i < cls.length; i++) {
                table.addCell(new PdfPCell(new Paragraph(cls[i].getNome())));
                table.addCell(new PdfPCell(new Paragraph(cls[i].getCpf())));
                table.addCell(new PdfPCell(new Paragraph(formatar.format(cls[i].getDataNascimento()))));
                table.addCell(new PdfPCell(new Paragraph(cls[i].getCargoOcupa())));
                table.addCell(new PdfPCell(new Paragraph((float) cls[i].getSalario())));
            }
            
            document.add(table);
            document.close();

        } catch (DocumentException de) {
            System.err.println(de.getMessage());
        } catch (IOException ioe) {
            System.err.println(ioe.getMessage());
        }
JOptionPane.showMessageDialog(null,"PDF gerado com Sucesso.!");
    }

    
    
    public void GeraCSV(Object vetor[], int tam) throws IOException{
        DateFormat formatar = DateFormat.getDateInstance();
    Funcionario v [] = new Funcionario[tam];
        for (int i = 0; i<tam; i++) {
            v[i] = (Funcionario) vetor[i];
        }
        FileWriter arq = new FileWriter("arquivo.csv");
        PrintWriter gravarArq = new PrintWriter(arq);
        gravarArq.printf("");
        for (int i = 0; i<v.length; i++) {
            gravarArq.print(v[i].getNome()+";"+v[i].getIdade()+";"+v[i].getCpf()+";"+v[i].getSexo()+";"+formatar.format(v[i].getDataNascimento())+";"
                +formatar.format(v[i].getDataAdmissao())+";"+v[i].getCargoOcupa()+";"+v[i].getSalario());
        }
        arq.close();
    }
}
