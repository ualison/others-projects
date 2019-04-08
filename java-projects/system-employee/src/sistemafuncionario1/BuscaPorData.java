/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package SistemaFuncionario1;

import java.text.DateFormat;
import java.text.ParseException;
import java.util.Date;
import javax.swing.JOptionPane;

/**
 *
 * @author Bruno
 */
public class BuscaPorData {

    public void ProcuraPorDataAlternativo(Date data1, Date data2, Object vetor[], int tam) throws ParseException {
        Funcionario aux;
        Date auxD;
        int cont = 0;
        if (data1.compareTo(data2) > 1) {
            auxD = data1;
            data1 = data2;
            data2 = auxD;
        }

        DateFormat tt = DateFormat.getDateInstance();
        Date nascimento, admissao;
        for (int i = 0; i < tam; i++) {
            aux = (Funcionario) vetor[i];
            nascimento = aux.getDataNascimento();
            admissao = aux.getDataAdmissao();

            /*
             data atual e maior retorna 1;
             as datas são igual =0;
             data atual e menor =-1
             */
            if ((nascimento.compareTo(data1) >= 0 && nascimento.compareTo(data2) <= 0) || (admissao.compareTo(data1) >= 0 && (admissao.compareTo(data2) <= 0))) {
                System.out.println(vetor[i]);
                cont++;
            }
        }
        if (cont == 0) {
            JOptionPane.showMessageDialog(null, "Nenhum Funcionário se encaixou nos parametros desejado entre as datas " + tt.format(data1) + " e " + tt.format(data2), "Atenção", JOptionPane.WARNING_MESSAGE);
        }

    }

    public void ProcuraPorData(Date data1, Date data2, Object vetor[], int tam) throws ParseException {
        Funcionario aux;
        Date auxD;
        int cont = 0;

        if (data1.compareTo(data1) > 1) {
            auxD = data1;
            data1 = data2;
            data2 = auxD;
        }

        String acumuladora = "";
        DateFormat tt = DateFormat.getDateInstance();
        Date nascimento, admissao;
        for (int i = 0; i < tam; i++) {
            aux = (Funcionario) vetor[i];
            nascimento = aux.getDataNascimento();
            admissao = aux.getDataAdmissao();
            if ((nascimento.compareTo(data1) >= 0 && nascimento.compareTo(data2) <= 0) || (admissao.compareTo(data1) >= 0 && (admissao.compareTo(data2) <= 0))) {
                acumuladora += vetor[i] + "\n";
                cont++;
            }
        }

        if (cont == 0) {
            JOptionPane.showMessageDialog(null, "Nenhum Funcionário se encaixou nos parametros desejado entre as datas " + tt.format(data1) + " e " + tt.format(data2), "Atenção", JOptionPane.WARNING_MESSAGE);
        } else {
            JOptionPane.showMessageDialog(null, acumuladora);
        }
        acumuladora = "";
    }

}
