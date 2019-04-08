package SistemaFuncionario1;

import java.text.ParseException;

/**
 *
 * @author Bruno
 */

public class SistemaDeCadastro {

    public static void main(String[] args) throws ParseException, Exception {
        
/*
        // PARTE PARA TESTE !
        DateFormat Formatar1 = DateFormat.getDateInstance();
        ImprimirFuncionario imprimirFuncionario = new ImprimirFuncionario();
        GuardadorDeFuncionarios guardadorDeFuncionarios = new GuardadorDeFuncionarios();
        Funcionario x1 = new Funcionario();
        x1.setNome("Luciana Soares");
        x1.setCpf("011.111.111.12");
        x1.setIdade(21);
        x1.setSalario(30000);
        x1.setSexo(Modifica('F'));
        x1.setDataAdmissao(Formatar1.parse("29/12/2000"));
        x1.setDatanascimentoo(Formatar1.parse("11/01/1995"));
        x1.setCargoOcupa("Gerente de Markting");
        guardadorDeFuncionarios.addObjeto(x1);

        x1 = new Funcionario();
        x1.setNome("Bruno Teixeira de Sousa");
        x1.setCpf("011.111.111.11");
        x1.setIdade(21);
        x1.setSalario(10000);
        x1.setSexo(Modifica('m'));
        x1.setDataAdmissao(Formatar1.parse("09/01/2015"));
        x1.setDatanascimentoo(Formatar1.parse("11/01/1994"));
        x1.setCargoOcupa("Gerente de TI");
        guardadorDeFuncionarios.addObjeto(x1);

        x1 = new Funcionario();
        x1.setNome("Bruno de Castro");
        x1.setCpf("011.111.111.11");
        x1.setIdade(21);
        x1.setSalario(20000);
        x1.setSexo(Modifica('F'));
        x1.setDataAdmissao(Formatar1.parse("29/12/2000"));
        x1.setDatanascimentoo(Formatar1.parse("22/11/1995"));
        x1.setCargoOcupa("Gerente de Markting");
        guardadorDeFuncionarios.addObjeto(x1);

        x1 = new Funcionario();
        x1.setNome("Bruna Maria do Carmo");
        x1.setCpf("011.111.111.11");
        x1.setIdade(21);
        x1.setSalario(20000);
        x1.setSexo(Modifica('F'));
        x1.setDataAdmissao(Formatar1.parse("29/12/2000"));
        x1.setDatanascimentoo(Formatar1.parse("22/11/1995"));
        x1.setCargoOcupa("Gerente de Markting");
        guardadorDeFuncionarios.addObjeto(x1);
        x1 = new Funcionario();

        x1.setNome("Lucivania da Costa");
        x1.setCpf("011.111.111.11");
        x1.setIdade(21);
        x1.setSalario(20000);
        x1.setSexo(Modifica('F'));
        x1.setDataAdmissao(Formatar1.parse("29/12/2000"));
        x1.setDatanascimentoo(Formatar1.parse("22/11/1995"));
        x1.setCargoOcupa("Gerente de Markting");
        guardadorDeFuncionarios.addObjeto(x1);

        // INICIO DO SISTEMA .
        String tSrp1, tSrp2, tSrp3, tSrp4;
        String hora;
        int Srp1, Srp2, Srp3, Srp4;
        int rpDW;
        Date atual = new Date();
        Scanner ler = new Scanner(System.in);
        Funcionario novoFuncionario = new Funcionario();

        if (guardadorDeFuncionarios.posicao > 0) {
            imprimirFuncionario.ImprimirAniversariantesDoDia(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
        }
        do {
            hora = CaptHora();
            LimparTela();
            Menu(guardadorDeFuncionarios.posicao, hora);
            Srp1 = Pergunta("", 1, 5);
            switch (Srp1) {
// 1 case: MENU P.                //Cadastrar Funcionarios.
                case 1:
                    do {
                        Informativo(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                        LimparTela();
                        SubMenus(" Cadastrar de Funcionário ");
                        System.out.println("Digite o nome do funcionario");
                        boolean VerificaNome;
                        String nome;
                        int RespostaDoNome = 2;
                        do {
                            nome = ler.nextLine();
                            VerificaNome = isInt(nome);
                            if (VerificaNome == true) {
                                System.out.println("Ops! provavelmente você digitou numeros em vez de letras. Tente novamente");
                            }
                            if (guardadorDeFuncionarios.VerificaFuncionarioNome(nome) != false) {
                                RespostaDoNome = Pergunta("Nome do Funcionário já existe! Tem certeza que Nome é: " + nome + " \n | 1- SIM, continue cadastrando o novo Funcionário \n | 2- NÃO, tente inserir um novo nome e continue a cadastrar o Funcionário ?", 1, 2);
                            }
                        } while (guardadorDeFuncionarios.VerificaFuncionarioNome(nome) != false && RespostaDoNome != 1 || VerificaNome != false);

                        novoFuncionario.setNome(nome);

                        String idades;
                        boolean verificaInt;
                        int qntIdade = 1;
                        System.out.println("Digite a idade do funcionario");
                        do {
                            idades = ler.nextLine();
                            verificaInt = isInt(idades);

                            if (verificaInt == true) {
                                qntIdade = Integer.parseInt(idades);
                                if (qntIdade < 18) {
                                    System.out.println("Ops ! Tentando cadastrar um menor de idade, tente novamente\n");
                                }
                            }
                            if (verificaInt == false) {
                                System.out.println("Ops! idade incorreta tente novamente.");
                            }
                        } while (qntIdade < 18 || verificaInt != true);
                        novoFuncionario.setIdade(Integer.parseInt(idades));

                        System.out.println("Digite o CPF do funcionario | Formato Ex.:(000.000.000.00)");
                        String VCPF;
                        do {
                            VCPF = ler.nextLine();
                            if (novoFuncionario.validaCPF(VCPF) != true) {
                                System.out.println("CPF invalido, Digite o CPF do funcionario novamente  | Formato Ex.:(000.000.000.00)");
                            }
                            if (guardadorDeFuncionarios.VerificaFuncionarioCPF(VCPF) != -1) {
                                System.out.println("CPF já existe, tente novamente!");
                            }
                        } while (novoFuncionario.validaCPF(VCPF) != true || guardadorDeFuncionarios.VerificaFuncionarioCPF(VCPF) != -1);

                        novoFuncionario.setCpf(VCPF);

                        System.out.println("O sexo do funcionário | Formato Ex.:(M/F/O)");
                        char Vsexo = 'x';
                        String Vsexoo;
                        do {
                            Vsexoo = ler.nextLine();
                            if (Vsexoo.length() == 1) {
                                Vsexo = Modifica(Vsexoo.charAt(0));
                                if (novoFuncionario.validaSexo(Vsexo) == false) {
                                    System.out.println("Ops! Sexo invalido | Formato Ex.:|(M)asculino/(F)eminino/(O)utros |");
                                }
                            } else {
                                System.out.println("Ops! você digitou algo inesperado, tente novamente");
                            }
                        } while (novoFuncionario.validaSexo(Vsexo) == false || Vsexoo.length() > 1);

                        novoFuncionario.setSexo(Vsexo);

                        //ler.nextLine(); // Esvaziar o buffer do teclado
                        int datanascimento;
                        String DataNascimento;
                        int VerificarDataNascimento = 1;
                        System.out.println("Digite a Data de Nascimento do funcionário | Formato Ex.: Dia/Mês/Ano");
                        do {

                            DataNascimento = ler.nextLine();
                            datanascimento = VerificaData(DataNascimento);
                            if (datanascimento == 0) {
                                System.out.println("\n Ops ! você digitou algo não valido, tente novamente !");
                            }

                            if (datanascimento == 1) {
                                VerificarDataNascimento = VerificarDatas(DataNascimento, 1);

                                if (VerificarDataNascimento < 0) {
                                    System.out.println("Data invalida você digitou uma data de aniversário maior ou igual a data atual, tente novamente, por favor!");
                                }
                            }
                        } while (datanascimento != 1 || VerificarDataNascimento != 1);
                        novoFuncionario.setDatanascimentoo(Formatar1.parse(DataNascimento));
                      
                        int ops1;
                        int dataadmissao;
                        String DataAdmissao;
                        int VerificaDataAdmissao = 1;
                        ops1 = Pergunta("A Data de Admissão desse novo Funcionário é a atual ?,\n deixe te ajudar e pegaremos a data atual para você ? 1- SIM ou 2- NÃO", 1, 2);
                        if (ops1 == 1) {
                            Date dataAtual = new Date();
                            novoFuncionario.setDataAdmissao(dataAtual);
                        } else {
                            System.out.println("Digite a Data de Admissão do funcionário | Formato Ex.: Dia/Mês/Ano");
                            do {
                                DataAdmissao = ler.nextLine();
                                dataadmissao = VerificaData(DataAdmissao);
                                System.out.println("dataadmissao:" + dataadmissao);
                                if (dataadmissao == 0) {
                                    System.out.println("Ops ! você digitou algo não valido, tente novamente !");
                                }                                                                
                                if (dataadmissao == 1) {
                                    VerificaDataAdmissao = VerificarDatas(DataAdmissao, 2);
                                    System.out.println("DataAdmissao [VerificaDataAdmissao]:" + VerificaDataAdmissao);
                                    if (VerificaDataAdmissao < 0) {
                                        //<=0
                                        System.out.println("Data invalida você digitou uma data de admissão maior que a data atual, tente novamente.");
                                    }
                                }
                            } while (dataadmissao != 1 || VerificaDataAdmissao < 0);

                            novoFuncionario.setDataAdmissao(Formatar1.parse(DataAdmissao));
                        }
                        System.out.println("Digite o Cargo que o Funcionário ira ocupar");
                        boolean verificaCargo;
                        String cargo;
                        do {
                            cargo = ler.nextLine();
                            verificaCargo = novoFuncionario.isInt(cargo);
                            if (verificaCargo == true) {
                                System.out.println("Ops! você digitou algo inesperado, tente novamente.");

                            }
                        } while (verificaCargo != false);

                        novoFuncionario.setCargoOcupa(cargo);
                        System.out.println("Digite o salário do Funcionário");
                        String salario;
                        int VerificaDouble;
                        do {
                            salario = ler.nextLine();
                            VerificaDouble = VerificaDouble(salario);
                            if (VerificaDouble == 1) {
                                System.out.println("Ops ! Digitou algo errado, tente novamente");
                            }
                        } while (VerificaDouble != 0);

                        novoFuncionario.setSalario(Double.parseDouble(salario));

                        // Adicionar o objeto novoFuncionario. ao vetor de objetos
                        guardadorDeFuncionarios.addObjeto(novoFuncionario);
                        novoFuncionario = new Funcionario();

                        rpDW = Pergunta("Deseja Inserir um NOVO FUNCIONÁRIO?:  1-SIM | 2- NÃO", 1, 2);

                    } while (rpDW != 2);

                    break;
//2 CASE MENU P.
                case 2:
                    if (guardadorDeFuncionarios.posicao > 0) {
                        do {
                            LimparTela();
                            SubMenuBuscar();
                            Srp2 = Pergunta("", 1, 4);
//submenu buscar
                            switch (Srp2) {
                                case 1:

                                    //      - BuscarPorTexto; CPF ou NOME do Funcionário
                                    LimparTela();
                                    String nomeBusca;
                                    boolean verificaBuscaPorTexto;
                                    SubMenus("Buscar Por Nome ou CPF");
                                    BuscaPorTexto buscarPorTexto = new BuscaPorTexto();
                                    System.out.println("Digite o NOME OU CPF do Funcionário Desejado ");
                                    do {
                                        nomeBusca = ler.nextLine();
                                        verificaBuscaPorTexto = isInt(nomeBusca);

                                        if (verificaBuscaPorTexto == true) {
                                            System.out.println("Ops!, provavelmente você digitou algo errado, Tente Novamente.");
                                        }

                                    } while (verificaBuscaPorTexto != false);
                                    buscarPorTexto.BuscaPorTextoAlternativo(nomeBusca, guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                                    ler.nextLine();
                                    break;
                                case 2:
                                    //  - BuscarPorNumero;
                                    String num1,
                                     num2;
                                    LimparTela();
                                    SubMenus("Buscar Por Salário");
                                    BuscaPorNumero buscarPorNumero = new BuscaPorNumero();
                                    int Rvalor1,
                                     Rvalor2;
                                    int RespostaG1 = 1,
                                     RespostaG2 = 1;
                                    int cont1,
                                     cont2;
                                    cont1 = cont2 = 0;
                                    double teste1 = 1;
                                    double teste2 = 1;

                                    System.out.println("Digiteo valor do salário Inicial");
                                    do { // PRIMEIRO DO WHILE, para que o usuário só possa digitar salários validos.

                                        num1 = ler.nextLine();
                                        Rvalor1 = VerificaDouble(num1);

                                        if (Rvalor1 == 1) {
                                            System.out.println("\n Ops! provavelmente você digitou algo errado, tente novamente e digite um valor de salário valido.");
                                            cont1++;
                                        }

                                        if (Rvalor1 == 0) {
                                            teste1 = Double.parseDouble(num1);
                                            if (teste1 <= 0) {
                                                System.out.println(" \n Ops!, provavelmente você digitou um salário igual a zeor ou negativo.");
                                            }
                                        }

                                        if (cont1 == 5) {
                                            RespostaG1 = Pergunta("\n Percebemos que você está tento um pouco de dificuldade,\nDeseja que atribuimos um valor aleatorio valido para o primeiro valor?. 1-SIM ou 2-NÃO ?", 1, 2);
                                            if (RespostaG1 == 1) {
                                                teste1 = GeraSalarioSo(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao, 1);
                                                cont1 = 0;
                                                Rvalor1 = 0;
                                            }
                                        }
                                    } while (Rvalor1 != 0 || teste1 <= 0 || RespostaG1 != 1);

                                    System.out.println("\n Digite o valor do salário Final");
                                    do {// SEGUNDO DO WHILE, para que o usuário só possa digitar salários validos.
                                        num2 = ler.nextLine();
                                        Rvalor2 = VerificaDouble(num2);
                                        
                                        if (Rvalor2 == 1) {
                                            System.out.println("\n Ops! provavelmente você digitou algo errado, tente novamente e digite um valor de salário valido.");
                                            cont2++;
                                        }
                                        if (Rvalor2 == 0) {
                                            teste2 = Double.parseDouble(num2);
                                            if (teste2 == 0){
                                                System.out.println(" \n Ops!, provavelmente você digitou um salário ou igual a zero ou negativo.");
                                            }
                                        }
                                        if (cont2 == 5) {
                                            RespostaG2 = Pergunta("\n Percebemos que você está tento um pouco de dificuldade,\n Deseja que atribuimos um valor aleatorio valido para o primeiro valor?. 1-SIM ou 2-NÃO ?", 1, 2);
                                            if (RespostaG2 == 1) {
                                                teste2 = GeraSalarioSo(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao, 2);
                                                Rvalor2 = 0;
                                                cont2 = 0;
                                            }
                                        }
                                    } while (Rvalor2 != 0 || teste2 <= 0 || RespostaG2 != 1);

                                    buscarPorNumero.BuscaPorNumero(teste1, teste2, guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                                    ler.nextLine();
                                    break;
                                case 3://   Buscar por Data

                                    String data1,
                                     data2;
                                    int RespostaData1,
                                     RespostaData2;
                                    int conData1 = 0,
                                     conData2 = 0;
                                    LimparTela();
                                    SubMenus("Buscar Por Data");
                                    BuscaPorData buscarPorData = new BuscaPorData();

                                    int ver1,
                                     ver2;

                                    System.out.println("Digite a primeira data | Formato Ex.: Dia/Mês/Ano");
                                    do {
                                        data1 = ler.nextLine();
                                        ver1 = VerificaData(data1);
                                        if (ver1 == 0) {
                                            System.out.println("Ops! A primeira data invalida ou incorreta, tente digitar a data novamente | Formato Ex.: Dia/Mês/Ano");
                                            conData1++;
                                            if (conData1 == 5) {
                                                RespostaData1 = Pergunta(" \n Detectamos que provavelmente você está tendo problemas em inserir uma data valida\n"
                                                        + " Deseja que nós ajude a preencher esse valor automaticamente ? 1-SIM OU 2-NÃO ?", 1, 2);
                                                if (RespostaData1 == 1) {
                                                    data1 = DataAleatoriamente(1);
                                                    ver1 = 1;
                                                }
                                            }
                                        }
                                    } while (ver1 != 1);

                                    System.out.println("Digite a segunda data | Formato Ex.: Dia/Mês/Ano");
                                    do {
                                        data2 = ler.nextLine();
                                        ver2 = VerificaData(data2);
                                        if (ver2 == 0) {
                                            System.out.println("Ops!A segunda data invalida ou incorreta, tente digitar a data novamente | Formato Ex.: Dia/Mês/Ano");
                                            conData2++;
                                            if (conData2 == 5) {
                                                RespostaData2 = Pergunta("\n Detectamos que provavelmente você está tendo problemas em inserir uma data valida\n"
                                                        + " Deseja que nós ajude a preencher esse valor automaticamente? 1-SIM OU 2-NÃO ?", 1, 2);
                                                if (RespostaData2 == 1) {
                                                    data2 = DataAleatoriamente(2);
                                                    ver2 = 1;
                                                }

                                            }
                                        }

                                    } while (ver2 != 1);
                                    buscarPorData.ProcuraPorDataAlternativo(Formatar1.parse(data1), Formatar1.parse(data2), guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                                    ler.nextLine();
                                    break;
                                case 4:// SAIR
                                    break;
                            }
                        } while (Srp2 != 4);
                    } else {
                        JOptionPane.showMessageDialog(null, "Nenhum Funcionário Cadastrado para ser Buscado.", "Atenção", JOptionPane.WARNING_MESSAGE);
                    }
                    break;// FIM DO CASE 2               
// 3 CASE MENU P.                    
                case 3:
                    if (guardadorDeFuncionarios.posicao > 0) {
                        do {
                            LimparTela();
                            SubMenuImprimir();
                            Srp3 = Pergunta("", 1, 9);
//SUBMENU IMPRIMIR
                            switch (Srp3) {

                                case 1:// IMPRIMIR TUDO
                                    LimparTela();
                                    SubMenus("Todos os Dados dos Funcionários");
                                    imprimirFuncionario.ImprimirTudo(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                                    ler.nextLine();
                                    break;
                                case 2:
                                    LimparTela();
                                    SubMenus("Todos os Dados dos Funcionários em ordem alfabetica");
                                    imprimirFuncionario.Ordenar(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                                    ler.nextLine();
                                    break;

                                case 3:// Funcionario com maior salario.
                                    LimparTela();
                                    SubMenus("Dados do Funcionário com maior salário dentro da Empresa");
                                    if (guardadorDeFuncionarios.posicao == 1) {
                                        System.out.println(guardadorDeFuncionarios.arrayDeObjetos[0]);
                                    } else {
                                        imprimirFuncionario.ImpirmirFuncionarioComMaiorSalario(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                                    }
                                    ler.nextLine();
                                    break;
                                case 4: // imprime funcionário com mais tempo na empresa.
                                    LimparTela();
                                    SubMenus("Dados do Funcionário com mais tempo dentro da Empresa");
                                    if (guardadorDeFuncionarios.posicao == 1) {
                                        System.out.println(guardadorDeFuncionarios.arrayDeObjetos[0]);
                                    } else {
                                        imprimirFuncionario.ImprimirFuncionarioComMaisTempoNaEmpresa(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                                    }
                                    ler.nextLine();
                                    break;
                                case 5: // IMPRIME APENAS CAMPOS NOME, CARGO E SALARIO DE TODOS OS FUNCIONARIOS
                                    LimparTela();
                                    SubMenus("Imprimir Nome,Cargo e Salários de todos os Funcionários");
                                    imprimirFuncionario.Impirmir3Campos(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                                    ler.nextLine();
                                    break;
                                case 6:
                                    //- imprime funcionário com mais novo.
                                    LimparTela();
                                    SubMenus("Dados do Funcionário mais novo dentro da Empresa");
                                    if (guardadorDeFuncionarios.posicao == 1) {
                                        System.out.println(guardadorDeFuncionarios.arrayDeObjetos[0]);
                                    } else {
                                        imprimirFuncionario.ImprimirFuncionarioMaisNovoAlt(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                                    }
                                    ler.nextLine();
                                    break;
                                case 7:
                                    LimparTela();
                                    SubMenus("Gasto Total com a Folha de Pagamento");
                                    FuncExtras ext = new FuncExtras();
                                    double total = GeraGastoComFuncionarios(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                                    System.out.println("Total da Folha de Pagamento dos Funcionários: " + total);
                                    ler.nextLine();
                                    break;
                                case 8:
                                    int poAtual = -1;
                                    do {
                                        LimparTela();
                                        AndarTabela();
                                        Srp4 = Pergunta("", 1, 5);
                                        switch (Srp4) {
                                            case 1: // Primeiro
                                                primeiro(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao, poAtual);
                                                poAtual = 0;
                                                ler.nextLine();
                                                break;
                                            case 2: // próximo
                                                proximo(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao, poAtual);
                                                poAtual++;
                                                ler.nextLine();
                                                break;
                                            case 3: // anterior
                                                anterior(guardadorDeFuncionarios.arrayDeObjetos, poAtual);
                                                poAtual--;
                                                ler.nextLine();
                                                break;
                                            case 4: // ultimo
                                                ultimo(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao, poAtual);
                                                poAtual = guardadorDeFuncionarios.posicao - 1;
                                                ler.nextLine();
                                                break;
                                            case 5: // SAIR 
                                                break;
                                        }
                                    } while (Srp4 != 5);

                                    break;
                                case 9:// SAIR
                                    break;
                            }
                        } while (Srp3 != 9);
                    } else {
                        JOptionPane.showMessageDialog(null, "Nenhum Funcionário Cadastrado para ser listado", "Atenção !", JOptionPane.WARNING_MESSAGE);
                    }
                    break; // FIM DO CASE 3
// QUARTO CASE
                case 4:
                    if (guardadorDeFuncionarios.posicao > 0) {

                        LimparTela();
                        SubMenus("Remover");
                        Funcionario aux;
                        String CpfRemover;
                        int remover;
                        imprimirFuncionario.Ordenar(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                        System.out.println("\n Digite o numero do CPF  do Funcionário que Deseja apagar: ");
                        do {
                            CpfRemover = ler.nextLine();
                            remover = guardadorDeFuncionarios.VerificaFuncionarioCPF(CpfRemover);
                            if (remover == -1) {
                                System.out.println("CPF não encontrado, tente novamente e digite um CPF valido");
                            }
                        } while (remover < 0);
                        int ConfirmaRemo = JOptionPane.showConfirmDialog(null, "Deseja realmente remover esse Funcionário?");
                        if (ConfirmaRemo == JOptionPane.YES_OPTION) {
                            guardadorDeFuncionarios.Remover(remover);
                            LimparTela();
                            imprimirFuncionario.ImprimirTudo(guardadorDeFuncionarios.arrayDeObjetos, guardadorDeFuncionarios.posicao);
                            JOptionPane.showMessageDialog(null, "Funcionário removido com sucesso !", "Atenção", JOptionPane.WARNING_MESSAGE);
                        } else {
                            JOptionPane.showMessageDialog(null, "Funcionário não removido", "Atenção", JOptionPane.WARNING_MESSAGE);
                        }
                    } else {
                        JOptionPane.showMessageDialog(null, "Nenhum Funcionário cadastrado para que possa ser removido", "Atenção", JOptionPane.WARNING_MESSAGE);
                    }
                    break;
                case 5: // SAIR
                    LimparTela();
                    JOptionPane.showMessageDialog(null, ""
                            + "      Tchua, Obrigado por usar o nosso sistema.!"
                            + "\n    Desenvolvedores: Alan, Bruno e Ualisson       "
                            + "\n    Professor: Bruno de Castro                    "
                            + "\n    2º Semestre de Ciência da Computação - UFC    "
                    );
                    break;
            }
        } while (Srp1 != 5);
    }*/
        
            java.awt.EventQueue.invokeLater(new Runnable() {
                public boolean janela = true;
            @Override
            public void run() {
                new sistemafuncionario1.Inicio().setVisible(janela);
            }
        });
    }

}
