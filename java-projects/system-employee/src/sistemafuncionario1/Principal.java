/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sistemafuncionario1;

import static SistemaFuncionario1.FuncExtras.DataAleatoriamente;
import static SistemaFuncionario1.FuncExtras.GeraSalarioSo;
import static SistemaFuncionario1.FuncExtras.VerificaData;
import static SistemaFuncionario1.FuncExtras.VerificaDouble;
import static SistemaFuncionario1.FuncExtras.VerificarDatas;
import static SistemaFuncionario1.Funcionario.Modifica;
import static SistemaFuncionario1.Funcionario.isInt;
//import com.jgoodies.looks.plastic.PlasticLookAndFeel;
//import com.jgoodies.looks.plastic.theme.InvertedColorTheme;
//import com.jgoodies.looks.plastic.theme.SkyYellow;
import java.io.IOException;
import java.text.DateFormat;
import java.text.ParseException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

/**
 *
 * @author Bruno
 */
public class Principal extends javax.swing.JFrame {

    SistemaFuncionario1.GuardadorDeFuncionarios guardador = new SistemaFuncionario1.GuardadorDeFuncionarios();
    SistemaFuncionario1.Funcionario NovoFuncionario = new SistemaFuncionario1.Funcionario();
    DateFormat Formatar1 = DateFormat.getDateInstance();
    SistemaFuncionario1.ImprimirFuncionario impri = new SistemaFuncionario1.ImprimirFuncionario();
    SistemaFuncionario1.BuscaPorTexto buscarPorTexto = new SistemaFuncionario1.BuscaPorTexto();
    SistemaFuncionario1.BuscaPorNumero buscarPorNumero = new SistemaFuncionario1.BuscaPorNumero();
    SistemaFuncionario1.BuscaPorData buscarPorData = new SistemaFuncionario1.BuscaPorData();
    public Principal() {
        initComponents();
        DesabilitaCampos();
        jBCadastrar.setEnabled(false);
        impri.ImprimirAniversariantesDoMesAlternativo(guardador.arrayDeObjetos, guardador.posicao);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel2 = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        jCImprimir = new javax.swing.JComboBox();
        jCBusca = new javax.swing.JComboBox();
        jLabel1 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        jCRelatorio = new javax.swing.JComboBox();
        jPCadastrar = new javax.swing.JPanel();
        jLabel12 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jTNome = new javax.swing.JTextField();
        jTIdade = new javax.swing.JTextField();
        jCSexo = new javax.swing.JComboBox();
        jFDataNascimento = new javax.swing.JFormattedTextField();
        jFDataAdmissao = new javax.swing.JFormattedTextField();
        jTCargo = new javax.swing.JTextField();
        jTSalario = new javax.swing.JTextField();
        jBNovo = new javax.swing.JButton();
        jBCadastrar = new javax.swing.JButton();
        jLabel9 = new javax.swing.JLabel();
        jFCpf = new javax.swing.JFormattedTextField();
        jBCancelar = new javax.swing.JButton();
        jPanel1 = new javax.swing.JPanel();
        jCCores = new javax.swing.JComboBox();
        jLabel11 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("CADFUNC - CADASTRAR FUNCIONÁRIO");
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowOpened(java.awt.event.WindowEvent evt) {
                formWindowOpened(evt);
            }
        });

        jLabel2.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        jLabel2.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel2.setText("Imprimir Funcionários");
        jLabel2.setBorder(javax.swing.BorderFactory.createTitledBorder(""));

        jCImprimir.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "...", "Todos os Funcionários", "Todos os Funcionários Ordem Alfabética", "Funcionário com maior salário", "Funcionário mais velho", "Imprimir Nome Cargo e Salário", "Funcionários mais novo" }));
        jCImprimir.setToolTipText("Selecione a opção de imprimir os dados do funcionário");
        jCImprimir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jCImprimirActionPerformed(evt);
            }
        });

        jCBusca.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "...", "Buscar por Texto (Nome ou CPF)", "Buscar por Número (Salário)", "Buscar por Data (Data nascimento ou Data Admissão)" }));
        jCBusca.setToolTipText("Selecione a opção que satisfaça melhor sua busca");
        jCBusca.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jCBuscaActionPerformed(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("Buscar Funcionário");
        jLabel1.setBorder(javax.swing.BorderFactory.createTitledBorder(""));

        jLabel10.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        jLabel10.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel10.setText("Relatórios");
        jLabel10.setBorder(javax.swing.BorderFactory.createTitledBorder(""));

        jCRelatorio.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "...", "Relatório em PDF", "Relatório em CSV" }));
        jCRelatorio.setToolTipText("Selecione a opção para gera o arquivo que deseja");
        jCRelatorio.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jCRelatorioActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jLabel10, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jCBusca, javax.swing.GroupLayout.Alignment.TRAILING, 0, 0, Short.MAX_VALUE)
                            .addComponent(jLabel1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jCImprimir, javax.swing.GroupLayout.Alignment.TRAILING, 0, 260, Short.MAX_VALUE)
                            .addComponent(jLabel2, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                    .addComponent(jCRelatorio, javax.swing.GroupLayout.Alignment.TRAILING, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 47, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jCImprimir, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 46, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jCBusca, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel10, javax.swing.GroupLayout.PREFERRED_SIZE, 41, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jCRelatorio, javax.swing.GroupLayout.PREFERRED_SIZE, 47, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(28, Short.MAX_VALUE))
        );

        jPCadastrar.setBorder(javax.swing.BorderFactory.createTitledBorder(javax.swing.BorderFactory.createTitledBorder("Cadastro de Dados")));

        jLabel12.setText("Nome:");

        jLabel3.setText("Idade:");

        jLabel4.setText("Sexo:");

        jLabel5.setText("Data de Nascimento:");

        jLabel6.setText("Data de Admissão:");

        jLabel7.setText("Cargo:");

        jLabel8.setText("Salário:");

        jTNome.setToolTipText("Digite o nome do Funcionário");

        jTIdade.setToolTipText("Digite a idade do Funcionário");

        jCSexo.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "??", "M", "F", "O" }));
        jCSexo.setToolTipText("Selecione  a opção que representa opção sexual do Funcionário");

        try {
            jFDataNascimento.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("##/##/####")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }
        jFDataNascimento.setToolTipText("Digite a Data de Nascimento do Funcionário");

        try {
            jFDataAdmissao.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("##/##/####")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }
        jFDataAdmissao.setToolTipText("Digite a Data de Admissão do Funcionário");

        jTCargo.setToolTipText("Digite o Cargo que do Funcionário");

        jTSalario.setToolTipText("Digiteo Salário do Funcionário");

        jBNovo.setText("Novo");
        jBNovo.setToolTipText("Novo Funcionário");
        jBNovo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jBNovoActionPerformed(evt);
            }
        });

        jBCadastrar.setText("Cadastrar");
        jBCadastrar.setToolTipText("Cadastrar o Funcionário");
        jBCadastrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jBCadastrarActionPerformed(evt);
            }
        });

        jLabel9.setText("Cpf:");

        try {
            jFCpf.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("###.###.###.##")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }
        jFCpf.setToolTipText("Digite o CPF do Funcionário");

        jBCancelar.setText("Cancelar");
        jBCancelar.setToolTipText("Cancelar operação");
        jBCancelar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jBCancelarActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPCadastrarLayout = new javax.swing.GroupLayout(jPCadastrar);
        jPCadastrar.setLayout(jPCadastrarLayout);
        jPCadastrarLayout.setHorizontalGroup(
            jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPCadastrarLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(jPCadastrarLayout.createSequentialGroup()
                        .addComponent(jBNovo, javax.swing.GroupLayout.PREFERRED_SIZE, 73, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jBCancelar)
                        .addGap(11, 11, 11)
                        .addComponent(jBCadastrar))
                    .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addGroup(jPCadastrarLayout.createSequentialGroup()
                                .addComponent(jLabel12)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jTNome))
                            .addGroup(jPCadastrarLayout.createSequentialGroup()
                                .addComponent(jLabel3)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jTIdade, javax.swing.GroupLayout.PREFERRED_SIZE, 207, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(jTCargo, javax.swing.GroupLayout.PREFERRED_SIZE, 197, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPCadastrarLayout.createSequentialGroup()
                                .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel5)
                                    .addComponent(jLabel6))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(jFDataNascimento, javax.swing.GroupLayout.DEFAULT_SIZE, 139, Short.MAX_VALUE)
                                    .addComponent(jFDataAdmissao))))
                        .addGroup(jPCadastrarLayout.createSequentialGroup()
                            .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jLabel7)
                                .addComponent(jLabel8))
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                            .addComponent(jTSalario, javax.swing.GroupLayout.PREFERRED_SIZE, 197, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addGroup(jPCadastrarLayout.createSequentialGroup()
                                .addComponent(jLabel9)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jFCpf))
                            .addGroup(jPCadastrarLayout.createSequentialGroup()
                                .addComponent(jLabel4)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jCSexo, javax.swing.GroupLayout.PREFERRED_SIZE, 103, javax.swing.GroupLayout.PREFERRED_SIZE)))))
                .addContainerGap(31, Short.MAX_VALUE))
        );
        jPCadastrarLayout.setVerticalGroup(
            jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPCadastrarLayout.createSequentialGroup()
                .addGap(21, 21, 21)
                .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel12)
                    .addComponent(jTNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel3)
                    .addComponent(jTIdade, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel4)
                    .addComponent(jCSexo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(6, 6, 6)
                .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel9)
                    .addComponent(jFCpf, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(jFDataNascimento, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6)
                    .addComponent(jFDataAdmissao, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(jTCargo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel8)
                    .addComponent(jTSalario, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(jPCadastrarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jBNovo, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jBCadastrar, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jBCancelar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jCCores.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "SILVER", "BLACK" }));
        jCCores.setToolTipText("Escolha uma opção para modificar a tela");
        jCCores.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jCCoresActionPerformed(evt);
            }
        });

        jLabel11.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        jLabel11.setText("TEMA");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addContainerGap(193, Short.MAX_VALUE)
                .addComponent(jLabel11)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jCCores, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(237, 237, 237))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addGap(0, 4, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jCCores, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel11)))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(10, 10, 10)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addContainerGap())
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jPCadastrar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(6, 6, 6)
                        .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(11, 11, 11)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jPCadastrar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jBNovoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jBNovoActionPerformed
        Limpa();
        HabilitaCampos();
        jBCadastrar.setEnabled(true);
    }//GEN-LAST:event_jBNovoActionPerformed

    private void jBCadastrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jBCadastrarActionPerformed

        boolean VerificaNome;
        String nome;
        int RespostaDoNome = 2;
        String idades;
        boolean verificaInt;
        int qntIdade;
        String VCPF;
        char Vsexo;
        String Vsexoo;
        int datanascimento;
        String DataNascimento;
        int VerificarDataNascimento = 1;
        int dataadmissao;
        String DataAdmissao;
        int VerificaDataAdmissao;
        boolean verificaCargo;
        String cargo;
        String salario;
        int VerificaDouble;

        nome = jTNome.getText();
        VerificaNome = isInt(nome);
        if (VerificaNome == true) {
            jTNome.setText("");
        }
        idades = jTIdade.getText();
        verificaInt = isInt(idades);

        if (verificaInt == true) {
            qntIdade = Integer.parseInt(idades);
            if (qntIdade < 18) {
                jTIdade.setText("");
            }
        }
        if (verificaInt == false) {
            jTIdade.setText("");
        }
        VCPF = jFCpf.getText();
        if (NovoFuncionario.validaCPF(VCPF) != true) {
            jFCpf.setText("");
        }
        if (guardador.VerificaFuncionarioCPF(VCPF) != -1) {
            jFCpf.setText("");
        }
        Vsexoo = (String) jCSexo.getSelectedItem();

        if (jCSexo.getSelectedItem() == "??") {
            jCSexo.setSelectedItem("??");
        }
        if (Vsexoo.length() == 1) {
            Vsexo = Modifica(Vsexoo.charAt(0));
            if (NovoFuncionario.validaSexo(Vsexo) == false) {
                jCSexo.setSelectedItem("??");
            }
        } else {
            jCSexo.setSelectedItem("??");
        }
        DataNascimento = jFDataNascimento.getText();
        datanascimento = VerificaData(DataNascimento);
        if (datanascimento == 0) {
            jFDataNascimento.setText("");
        }
        if (datanascimento == 1) {
            try {
                VerificarDataNascimento = VerificarDatas(DataNascimento, 1);
            } catch (ParseException ex) {
                Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
            }
            if (VerificarDataNascimento < 0) {
                jFDataNascimento.setText("");
            }
        }

        DataAdmissao = jFDataAdmissao.getText();
        dataadmissao = VerificaData(DataAdmissao);
        if (dataadmissao == 0) {
            jFDataAdmissao.setText("");
        }
        if (dataadmissao == 1) {
            try {
                VerificaDataAdmissao = VerificarDatas(DataAdmissao, 2);

                if (VerificaDataAdmissao < 0) {

                    jFDataAdmissao.setText("");
                }
            } catch (ParseException ex) {
                Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        cargo = jTCargo.getText();
        verificaCargo = NovoFuncionario.isInt(cargo);
        if (verificaCargo == true) {
            jTCargo.setText("");
        }

        salario = jTSalario.getText();
        VerificaDouble = VerificaDouble(salario);
        if (VerificaDouble == 1) {
            jTSalario.setText("");
        }

        if (VerificaDados()) {
            NovoFuncionario.setNome(jTNome.getText());
            NovoFuncionario.setIdade(Integer.parseInt(jTIdade.getText()));
            NovoFuncionario.setCpf(jFCpf.getText());
            Vsexoo = (String) jCSexo.getSelectedItem();
            NovoFuncionario.setSexo(Vsexoo.charAt(0));
            try {
                NovoFuncionario.setDataAdmissao(Formatar1.parse(jFDataAdmissao.getText()));
                NovoFuncionario.setDatanascimentoo(Formatar1.parse(jFDataNascimento.getText()));
            } catch (ParseException ex) {
                Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
            }
            NovoFuncionario.setCargoOcupa(jTCargo.getText());
            NovoFuncionario.setSalario(Double.parseDouble(jTSalario.getText()));
            guardador.addObjeto(NovoFuncionario);
            Limpa();
            DesabilitaCampos();
            jBCadastrar.setEnabled(false);
            NovoFuncionario = new SistemaFuncionario1.Funcionario();
            JOptionPane.showMessageDialog(null, "Funcionário Cadastrado com Sucesso");
        } else {
            JOptionPane.showMessageDialog(null, "Revifique se não esqueceu de preencher algum campo");
        }

        
               
    }//GEN-LAST:event_jBCadastrarActionPerformed

    private void formWindowOpened(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowOpened

    }//GEN-LAST:event_formWindowOpened

    private void jCImprimirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jCImprimirActionPerformed
        String acao;
        acao = (String) jCImprimir.getSelectedItem();
        if (guardador.posicao > 0) {
            switch (acao) {
                case "Todos os Funcionários":
                    impri.ImprimirTudoAlternativo(guardador.arrayDeObjetos, guardador.posicao);
                    impri.ImprimirTudo(guardador.arrayDeObjetos, guardador.posicao);
                    break;
                case "Todos os Funcionários Ordem Alfabética":
                    impri.ImprimirTudoAlternativo(guardador.arrayDeObjetos, guardador.posicao);
                    break;
                case "Funcionário com maior salário":
                    impri.ImpirmirFuncionarioComMaiorSalarioAlternativo(guardador.arrayDeObjetos, guardador.posicao);
                    break;
                case "Funcionário mais velho":
                    impri.ImprimirFuncionarioComMaisTempoNaEmpresaAlternativo(guardador.arrayDeObjetos, guardador.posicao);
                    break;
                case "Imprimir Nome Cargo e Salário":
                    impri.Impirmir3CamposAlternativo(guardador.arrayDeObjetos, guardador.posicao);
                    break;
                case "Funcionários mais novo":
                    impri.ImprimirFuncionarioMaisNovoAlt(guardador.arrayDeObjetos, guardador.posicao);
                    break;
            }
        } else {
            JOptionPane.showMessageDialog(null, "Nenhum Funcionário Cadastrado");
        }
        jCImprimir.setSelectedItem("??");
    }//GEN-LAST:event_jCImprimirActionPerformed

    private void jCCoresActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jCCoresActionPerformed
        String item = (String) jCCores.getSelectedItem();
        switch (item) {
            case "1":
                PlasticLookAndFeel.setPlasticTheme(new SkyYellow());
                break;
            case "2":
                PlasticLookAndFeel.setPlasticTheme(new InvertedColorTheme() {
                });
                break;
        }
        try {
            UIManager.setLookAndFeel("com.jgoodies.looks.plastic.Plastic3DLookAndFeel");
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
        } catch (UnsupportedLookAndFeelException ex) {
            Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
        }
        SwingUtilities.updateComponentTreeUI(this);
    }//GEN-LAST:event_jCCoresActionPerformed

    private void jCBuscaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jCBuscaActionPerformed
        String opBuscar;
        String nome;
        boolean VerificarBuscaPorTexto;

        double Dvalor1 = 0, Dvalor2 = 0;
        int ValidaValor2;
        int RespostaSalario1 = 0, RespostaSalario2 = 0;
        int Cont1 = 0, Cont2 = 0;
        int ValidaValor1;
        String Data2,Data1;
        opBuscar = (String) jCBusca.getSelectedItem();
        if(guardador.posicao >0){
        switch (opBuscar) {
            case "Buscar por Texto (Nome ou CPF)":
                do {
                    nome = JOptionPane.showInputDialog("DIGITE O NOME OU CPF DO FUNCIONÁRIO DESEJADO");
                    VerificarBuscaPorTexto = isInt(nome);
                    if (VerificarBuscaPorTexto == true) {
                        JOptionPane.showMessageDialog(null, "OPS! PROVAVELMENTE VOCÊ DIGITOU ALGO ERRADO, TENTE NOVAMENTE");
                    }
                } while (VerificarBuscaPorTexto != false);
                buscarPorTexto.BuscaPorTextoAlternativo(nome, guardador.arrayDeObjetos, guardador.posicao);

                break;
            case "Buscar por Número (Salário)":
                do {
                    String valor1 = JOptionPane.showInputDialog("DIGITE O PRIMEIRO VALOR");
                    ValidaValor1 = VerificaDouble(valor1);
                    if (ValidaValor1 == 1) {
                        JOptionPane.showMessageDialog(null, "Provavaelmente você digitou algo errado, tente novamente e digite um valor de salário valido");
                        Cont1++;
                    }
                    if (ValidaValor1 == 0) {
                        Dvalor1 = Double.parseDouble(valor1);
                        if (Dvalor1 <= 0) {
                            JOptionPane.showMessageDialog(null, "Ops! Provavelmente você digitou um salário igual a zero ou negativo, assim sua busca ficara menos eficiente. Tente novamente");
                        }
                    }
                    if (Cont1 == 5) {
                        RespostaSalario1 = JOptionPane.showConfirmDialog(null, "Percebemos que você está tento um pouco de dificuldade. \n Deseja que atribuimos um valor aleatorio valido para o primeiro valor de salário?.");
                        if (RespostaSalario1 == 0) {
                            Dvalor1 = GeraSalarioSo(guardador.arrayDeObjetos, guardador.posicao, 1);
                            Cont1 = 0;
                            ValidaValor1 = 0;
                        }
                    }
                } while (ValidaValor1 != 0 || Dvalor1 <= 0.0 || RespostaSalario1 != 0);

                do {
                    String valor2 = JOptionPane.showInputDialog("DIGITE O SEGUNDO VALOR");
                    ValidaValor2 = VerificaDouble(valor2);

                    if (ValidaValor2 == 1) {
                        JOptionPane.showMessageDialog(null, "Provavaelmente você digitou algo errado, tente novamente e digite um valor de salário valido");
                        Cont2++;
                    }
                    if (ValidaValor2 == 0) {
                        Dvalor2 = Double.parseDouble(valor2);
                        if (Dvalor2 <= 0) {
                            JOptionPane.showMessageDialog(null, "Ops! Provavelmente você digitou um salário igual a zero ou negativo, assim sua busca ficara menos eficiente. Tente novamente");
                        }
                    }

                    if (Cont2 == 5) {
                        RespostaSalario2 = JOptionPane.showConfirmDialog(null, "Percebemos que você está tento um pouco de dificuldade. \n Deseja que atribuimos um valor aleatorio valido para o primeiro valor de salário?.");
                        if (RespostaSalario2 == 0) {
                            Dvalor2 = GeraSalarioSo(guardador.arrayDeObjetos, guardador.posicao, 2);
                            Cont2 = 0;
                            ValidaValor2 = 0;
                        }
                    }
                } while (ValidaValor2 != 0 || Dvalor2 <= 0 || RespostaSalario2 != 0);
                buscarPorNumero.BuscaPorNumeroAlternativo(Dvalor1, Dvalor2, guardador.arrayDeObjetos, guardador.posicao);
                break;
            case "Buscar por Data (Data nascimento ou Data Admissão)":
                int VerificarData1,
                 VerificarData2;
                int ContData1 = 0,
                 ContData2 = 0;
                int RespostaData1,
                 RespostaData2;
                do {
                    Data1 = JOptionPane.showInputDialog("DIGITE A PRIMEIRA DATA.");
                    VerificarData1 = VerificaData(Data1);
                    if (VerificarData1 == 0) {
                        JOptionPane.showMessageDialog(null, "Ops! A primeira data provavelmente você não digitou no formato correto. Tente novamente Formato Ex.: Dia/Mês/Ano \n");

                        ContData1++;
                        if (ContData1 == 5) {
                            RespostaData1 = JOptionPane.showConfirmDialog(null, " \n Detectamos que provavelmente você está tendo problemas em inserir uma data valida\n"
                                    + " Deseja que nós ajude a preencher esse valor automaticamente ? ");
                            if (RespostaData1 == 0) {
                                Data1 = DataAleatoriamente(1);
                                VerificarData1 = 1;
                            }
                        }
                    }
                } while (VerificarData1 != 1);
                do {
                    Data2 = JOptionPane.showInputDialog("DIGITE A SEGUNDA DATA.");
                    VerificarData2 = VerificaData(Data2);
                    if (VerificarData2 == 0) {
                        JOptionPane.showMessageDialog(null, "Ops! A primeira data provavelmente você não digitou no formato correto. Tente novamente Formato Ex.: Dia/Mês/Ano \n");
                        ContData2++;
                        if (ContData2 == 5) {
                            RespostaData2 = JOptionPane.showConfirmDialog(null, " \n Detectamos que provavelmente você está tendo problemas em inserir uma data valida\n"
                                    + " Deseja que nós ajude a preencher esse valor automaticamente ? ");
                            if (RespostaData2 == 0) {
                                Data2 = DataAleatoriamente(2);
                                VerificarData2 = 1;
                            }
                        }
                    }
                } while (VerificarData2 != 1);
        {
            try {
                buscarPorData.ProcuraPorData(Formatar1.parse(Data1), Formatar1.parse(Data2), guardador.arrayDeObjetos, guardador.posicao);
            } catch (ParseException ex) {
                Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
                break;
        }
        }else{
            JOptionPane.showMessageDialog(null, "Nenhum Funcionário Cadastrado");
        }
        jCBusca.setSelectedItem("??");
    }//GEN-LAST:event_jCBuscaActionPerformed

    private void jBCancelarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jBCancelarActionPerformed
        Limpa();
        DesabilitaCampos();
        jBCadastrar.setEnabled(false);
    }//GEN-LAST:event_jBCancelarActionPerformed

    private void jCRelatorioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jCRelatorioActionPerformed
       String item = (String) jCRelatorio.getSelectedItem();
       if(guardador.posicao>0){
        switch (item) {
            case "Relatório em PDF":
                impri.GeraPDF(guardador.arrayDeObjetos,guardador.posicao);
                break;
            case "Relatório em CSV":
       {
           try {
               impri.GeraCSV(guardador.arrayDeObjetos,guardador.posicao);
           } catch (IOException ex) {
               Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
           }
       }
       JOptionPane.showMessageDialog(null,"CSV gerado com Sucesso.!");
                break;
        }
       }else{
       JOptionPane.showMessageDialog(null,"Você está tentando gerar um arquio, porém não tem nenhum funcionário cadastrado");
       }
       jCRelatorio.setSelectedItem("??");
       
    }//GEN-LAST:event_jCRelatorioActionPerformed

    

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jBCadastrar;
    private javax.swing.JButton jBCancelar;
    private javax.swing.JButton jBNovo;
    private javax.swing.JComboBox jCBusca;
    private javax.swing.JComboBox jCCores;
    private javax.swing.JComboBox jCImprimir;
    private javax.swing.JComboBox jCRelatorio;
    private javax.swing.JComboBox jCSexo;
    private javax.swing.JFormattedTextField jFCpf;
    private javax.swing.JFormattedTextField jFDataAdmissao;
    private javax.swing.JFormattedTextField jFDataNascimento;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPCadastrar;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JTextField jTCargo;
    private javax.swing.JTextField jTIdade;
    private javax.swing.JTextField jTNome;
    private javax.swing.JTextField jTSalario;
    // End of variables declaration//GEN-END:variables

    private void Limpa() {
        jCSexo.setSelectedItem("??");
        jTNome.setText("");
        jTIdade.setText("");
        jFCpf.setText("");
        jTCargo.setText("");
        jTSalario.setText("");
        jFDataAdmissao.setText("");
        jFDataNascimento.setText("");
    }

    private void DesabilitaCampos() {
        jTNome.setEnabled(false);
        jTIdade.setEnabled(false);
        jFCpf.setEnabled(false);
        jTCargo.setEnabled(false);
        jTSalario.setEnabled(false);
        jFDataAdmissao.setEnabled(false);
        jFDataNascimento.setEnabled(false);
        jCSexo.setEnabled(false);
    }

    private void HabilitaCampos() {
        jCSexo.setEnabled(true);
        jTNome.setEnabled(true);
        jTIdade.setEnabled(true);
        jFCpf.setEnabled(true);
        jTCargo.setEnabled(true);
        jTSalario.setEnabled(true);
        jFDataAdmissao.setEnabled(true);
        jFDataNascimento.setEnabled(true);
    }

    private boolean VerificaDados() {
        if (!jTNome.getText().equals("")
                & !jTIdade.getText().equals("")
                & !jFCpf.getText().equals("   .   .   .  ")
                & !jTCargo.getText().equals("")
                & !jFDataNascimento.getText().equals("  /  /    ")
                & !jFDataAdmissao.getText().equals("  /  /    ")
                & !jCSexo.getSelectedItem().equals("??")
                ) {
            return true;
        } else {
            return false;
        }
    }
}
