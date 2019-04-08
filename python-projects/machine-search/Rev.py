import json
import math
from nltk.tokenize import word_tokenize
from nltk.stem import PorterStemmer
import webbrowser
import sys


with open(sys.argv[1], 'r') as fp:
    H = json.load(fp)
with open(sys.argv[2], 'r') as fp:
    doc_reference = json.load(fp)

def Sort(tup):
      return(sorted(tup, key = lambda x: float(x[1]), reverse = True))


pesquisa =''

while(pesquisa != '*'):
    print('\ndigite * para sair')
    pesquisa = input('Digite um termo para pesquisar: ')

    tokens = word_tokenize(pesquisa.lower())

    ps = PorterStemmer()

    hashTableVector = dict()

    for w in tokens:
        count = tokens.count(w)
        w = ps.stem(w)
        hashTableVector[w] = count

    R = dict()

    for token in hashTableVector:
        if token in H:
            I = H[token][0] #IDF em H
            K = hashTableVector[token] # tf de token em hashTableVector
            W = K * I
            hashTableVector[token] = W
            L = H[token]
            soma = 0
            for tokenOcurrence in L:
                if type(tokenOcurrence) is list:
                    D = tokenOcurrence[0]
                    C = tokenOcurrence[1]
                    if D not in R:
                         R[D] = 0
                    R[D] += W * I * C
            soma = 0
            for tokenConsulta in hashTableVector:
                soma+= math.pow(hashTableVector[tokenConsulta], 2)
            L = math.sqrt(soma)
            for documento in R:
                S  = R[documento]
                tupla = doc_reference[documento]
                Y = tupla[1]
                Normalize = S /(L * Y)
                R[documento] = Normalize
        else: print('\nNADA ENCONTRADO!')


        resultado = sorted(R.items(), key=lambda x: float(x[1]), reverse=True)

        if(resultado != []):
            for res  in resultado:
                print(res)
            doc = input('\nDigite qual documento deseja abrir: ')
            resultado = dict((x, y) for x, y in resultado)
            if doc in resultado:
                    docKey = doc_reference[doc]
                    webbrowser.open_new('file://' + docKey[0])
                    break
            else:
                    print('\nO documento digitado não está nos resultados da pesquisa!')
                    break

