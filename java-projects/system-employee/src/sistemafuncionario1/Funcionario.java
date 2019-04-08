/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package SistemaFuncionario1;

import java.text.DateFormat;

import java.util.Date;

/**
 *
 * @author Bruno
 */
public class Funcionario implements Comparable<Funcionario> {

    private String nome;
    private int idade;
    private char sexo;
    private String cpf;
    private Date DataNascimento;
    private Date DataAdmissao;
    private String CargoOcupa;
    private double salario;

    public Funcionario() {
    }

    public Funcionario(String nome, int idade, char sexo, String cpf, String CargoOcupa, double salario, Date DataNascimentoo, Date Dataadmissao) {
        this.nome = nome;
        this.idade = idade;
        this.sexo = sexo;
        this.cpf = cpf;
        this.CargoOcupa = CargoOcupa;
        this.salario = salario;
        this.DataNascimento = DataNascimentoo;
        this.DataAdmissao = Dataadmissao;
    }

    public Date getDataNascimento() {
        return this.DataNascimento;
    }

    public void setDatanascimentoo(Date nascimento) {

        this.DataNascimento = nascimento;
    }

    public Date getDataAdmissao() {
        return this.DataAdmissao;
    }

    public void setDataAdmissao(Date admiss) {

        this.DataAdmissao = admiss;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public char getSexo() {
        return sexo;
    }

    public void setSexo(char sexo) {
        this.sexo = sexo;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getCargoOcupa() {
        return CargoOcupa;
    }

    public void setCargoOcupa(String cargoOcupa) {
        CargoOcupa = cargoOcupa;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }
    
    DateFormat formatar = DateFormat.getDateInstance();
    
    public String toString() {
        return "| NOME: " + nome + " | IDADE: " + idade + " | CPF: " + cpf + " | DATA NASCIMENTO: " + formatar.format(DataNascimento) + " | Sexo:" + sexo + " | DATA ADMISSÃO: " + formatar.format(DataAdmissao) + " | CARGO OCUPADO: " + CargoOcupa + " | SALARIO: " + salario + "|";
    }

    // Ele ira validar se CPF e um CPF valido perante a nomeclatura de 14 digitos.
    public boolean validaCPF(String cpf) {        
        char aux;
        String carac = "!@#$%,.;:-+'´[]{}^~¬|\\//";        
        
        for (int i = 0; i < carac.length(); i++) {
            aux = carac.charAt(i);
            cpf = cpf.replace(Character.toString(aux), ".");
        }
        
        if (cpf.length() >= 14) {
            return true;
        } else {
            return false;
        }

    }

    /*
     verifica se está cadastrando um sexo valido. 
     Obs: o significa outros.
     */
    public boolean validaSexo(char s) {
        if (s == 'm' || s == 'M' || s == 'f' || s == 'F' || s == 'o' || s == 'O') {
            return true;
        } else {
            return false;
        }
    }

    public static char Modifica(char x) {
        if (x == 'm') {
            x = 'M';
        } else if (x == 'f') {
            x = 'F';
        } else if (x == 'o') {
            x = 'O';
        }
        return x;
    }

    public static boolean isInt(String str) {
        boolean isInteger = true;
        int size = str.length();
        if (str.equals("")) {
            isInteger = false;
        }
        for (int i = 0; (i < size) && isInteger; i++) {
            isInteger = Character.isDigit(str.charAt(i));
        }
        return isInteger;
    }

    @Override
    public int compareTo(Funcionario f) {
        return nome.compareTo(f.getNome());
    }
    
}
