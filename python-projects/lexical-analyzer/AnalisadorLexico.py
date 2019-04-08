ALFA = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j','k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                'x', 'w', 'y', 'z', 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','W','Y','Z']

NUM = ['0','1','2','3','4','5','6','7','8','9']

# VERIFICAR SE UM ID É UM TOKEN DE UMA PALAVRA RESERVADA DA LINGUAGEM TINY
TOKENS_OR_ID = {
    'if': 'IF',
    'then': 'THEN',
    'else': 'ELSE',
    'end': 'END',
    'repeat': 'REPEAT',
    'until': 'UNTIL',
    'read': 'READ',
    'write': 'WRITE',
}
# ESTADOS DO NFA E SEUS TOKENS ASSOCIADOS
ACEITACAO_TOKENS_NFA = {
    '3': 'ID',
    '6':'NUM',
    '8':'ADD',
    '27':'SUB',
    '26':'DIV',
    '25':'MULT',
    '24':'EQUAL',
    '23':'LESS',
    '22':'LPAREN',
    '21':'RPAREN',
    '20':'POINTCOMMA',
    '19':'ATRIB'
}
#NFA PARA A LINGUAGEM TINY
SIGMA = ['+', '-', '/', '*', '=', '<', '(', ')', '.', ':',';', 'ALFA', 'NUM']
ESTADOS_ACEITACAO_NFA = ['3','6','8','19','20','21','22','23','24','25','26','27']
TRANSICOES = dict()
TRANSICOES[('1', '$')] = ['2','5','7','9','10','11','12','13','14','15','16','17']
TRANSICOES[('2', 'ALFA')] = ['3']
TRANSICOES[('3', '$')] = ['2']
TRANSICOES[('3', 'NUM')] = ['4']
TRANSICOES[('4', '$')] = ['3']
TRANSICOES[('5', 'NUM')] = ['6']
TRANSICOES[('6', '$')] = ['5']
TRANSICOES[('7', '+')] = ['8']
TRANSICOES[('9', '-')] = ['27']
TRANSICOES[('10', '/')] = ['26']
TRANSICOES[('11', '*')] = ['25']
TRANSICOES[('12', '=')] = ['24']
TRANSICOES[('13', '<')] = ['23']
TRANSICOES[('14', '(')] = ['22']
TRANSICOES[('15', ')')] = ['21']
TRANSICOES[('16', ';')] = ['20']
TRANSICOES[('17', ':')] = ['18']
TRANSICOES[('18', '=')] = ['19']
#NFA - FIM

#NFA - para a linguagem (10)* - USAR COMO TESTE
SIGMA2 = ['0','1']
ESTADOS_ACEITACAO2 = ['6']
TRANSICOES2 = dict()
TRANSICOES2[('1', '$')] = ['2','6']
TRANSICOES2[('2', '1')] = ['3']
TRANSICOES2[('3', '$')] = ['4']
TRANSICOES2[('4', '0')] = ['5']
TRANSICOES2[('5', '$')] = ['6', '2']

# Classe contendo os métodos de conversão do NFA para um DFA
class NFAtoDFA:

    #Conunjo de estados de aceitação do DFA gerado
    ESTADOS_TOKENS_DFA = {}

    #Retorna o conjunto dos estados alcançaveis a partir de s(Tupla) em NFA
    def edge(self, s, NFA)-> list():
        edgeSet = []
        for st in NFA:
            if st == s:
             edgeSet.append(NFA[s])
             return edgeSet
        return edgeSet

    #Retorna o conjunto dos estados alcançaveis a partir de S não consumindo nada
    def eclosure(self, S, NFA) -> list():
            aux = list()
            clos = list(self.edge(s = S, NFA= NFA))
            for e in clos:
                for a in e:
                  aux.append(a)
            aux.append(S[0])
            aux = sorted(aux)
            return aux
    #Ler um um conjunto de estados d e retorna um conjunto de estados consumindo c
    def DFAedge(self, d, c, NFA) -> list():
        dfalist = []
        if d != []:
          for s in d:
            for r in NFA:
                if s == r[0] and c == r[1]:
                  dfalist.append(NFA[r])
                  st = ''.join(NFA[r])
                  closureNext = self.eclosure(S = (st, '$'), NFA = NFA)
                  dfalist = closureNext
        return dfalist

    #verifica se uma lista lst existe em um dicionário dict de listas, retorna True e o índice
    def contains(self, lst, dic)-> (bool, int):
        for i, item in enumerate(dic):
            if dic[i] != [] and dic[i] == lst:
                return (True, i)
        return (False, -1)

    #converte um NFA em um DFA - algoritmo de conversão do slide
    def convertNFAtoDFA(self, sigma, NFAtrans)-> dict():
        trans = dict()
        states = dict()
        states[0] = []
        states[1] = self.eclosure(S= ('1', '$'), NFA= NFAtrans)
        p = 1
        j = 0
        while j <= p:
            for s in sigma:
                e = self.DFAedge(d = states[j], c = s, NFA= NFAtrans)
                verify = self.contains(e, states)
                if verify[0] == True:
                    tuplaKey =(str(j), s)
                    trans[tuplaKey] = str(verify[1])
                else:
                    if e != []:
                        p +=1
                        states[p] = e
                        tuplaKey = (str(j), s)
                        trans[tuplaKey] = str(p)
            j+=1
        #print(states)
        self.ESTADOS_TOKENS_DFA = self.estadosfinaisDFA(DFAtable=states, NFAstatesfinal=ESTADOS_ACEITACAO_NFA)
        print(self.ESTADOS_TOKENS_DFA)
        return trans

    #ler um arquivo contendo um programa em TINY
    def lerarquivotiny(self)-> str():
        ref_arquivo = open("C:/Users/ualis/Desktop/programa.tiny", "r")
        tiny = str()

        for linha in ref_arquivo:
            tiny+=linha
        ref_arquivo.close()

        lst = tiny.split()
        for i, item in enumerate(lst):
            if lst[i] == '{':
                j = i;
                while( lst[j] != '}'):
                    lst.remove(lst[j]);
                j = j + 1
        for a in lst:
            if a == '}':
                lst.remove(a)
        return lst

    def verificatransicao(self, transicao)->str():
        for a in ALFA:
            if transicao == a:
                return 'ALFA'
        for a in NUM:
            if transicao == a:
                return 'NUM'
        return transicao

    #cria uma list contendo os stados finais do DFA
    def estadosfinaisDFA(self, DFAtable, NFAstatesfinal)-> dict():
        DFAstatesfinal = {}
        for i in DFAtable:
            for a in DFAtable[i]:
                for b in NFAstatesfinal:
                    if a == b:
                        DFAstatesfinal[str(i)] = ACEITACAO_TOKENS_NFA[b]
        return DFAstatesfinal

    #computa uma cadeia no DFA
    def computaDFA(self, cadeia, DFA, estadoAtual)-> str():
        if(len(cadeia) == 1):
             for a in DFA:
                if estadoAtual == a[0] and a[1] == self.verificatransicao(transicao=cadeia):
                       return str(DFA[a])
        for a in DFA:
             if estadoAtual == a[0] and a[1] == self.verificatransicao(transicao=cadeia[0]):
                return self.computaDFA(cadeia = cadeia[1:], DFA=DFA, estadoAtual= str(DFA[a]))

    #verifica se um ID é uma palavra reservada da linguagem TINY
    def veficatokenID(self, id):
        for a in TOKENS_OR_ID:
            if a == id:
                return TOKENS_OR_ID[a]
        return 'ID('+id+')'

    #imprime os tokens relacionados a cada string no arquivo programa.tiny
    def imprimetokens(self, lst_strings, DFA):
        lst = []
        for a in lst_strings:
            stateFinal = self.computaDFA(cadeia= a, DFA=DFA, estadoAtual='1')
            if stateFinal == None:
                lst.append('TOKEN NOT EXIST')
            else:
                if self.ESTADOS_TOKENS_DFA[stateFinal] == 'ID':
                    lst.append(self.veficatokenID(id=a))
                else:
                    lst.append(self.ESTADOS_TOKENS_DFA[stateFinal]+'('+a+')')
        print(lst)


#chamada do objeto da classe NFAtoDFA
obj = NFAtoDFA()
print("CONJUNTO DE ESTADOS FINAIS DO DFA E SEUS TOKENS")
DFA = obj.convertNFAtoDFA(sigma=SIGMA, NFAtrans = TRANSICOES)
print('\n'+"DFA CONVERTIDO")
print(DFA)
print('\n'+"STRINGS DO ARQUIVO programa.tiny")
print(obj.lerarquivotiny())
print('\n'+"ANALISADOR LÉXICO")
obj.imprimetokens(lst_strings=obj.lerarquivotiny(), DFA=DFA)
