from Document import Document
import math
import json
import os
import sys

DOC_REFERENCE = dict()
DOCS_PATH = dict()


#directory = "C:/Users/ualis/Desktop/REV/"
directory = sys.argv[1]

H = dict()
N = len(os.listdir(directory))
for i, filename in enumerate(os.listdir(directory)):
    if filename.endswith(".txt") or filename.endswith(".html") or filename.endswith(".story"):
        path = os.path.join(directory, filename)
        print('Documentos Indexados: ', i)
        doc = Document(i+1, filename, directory)
        HashTableVector = doc.to_vector()
        for token in HashTableVector:
            idDoc = 'D'+str(doc.getID())
            DOCS_PATH[idDoc] = path
            if token not in H:
                TokenInfo = list()
                TokenInfo.append(0)
                tupla = (idDoc, HashTableVector[token])
                TokenInfo.append(tupla)
                H[token] = TokenInfo
                DOC_REFERENCE[idDoc] = 0
            else:
                DOC_REFERENCE[idDoc] = 0
                tupla = (idDoc, HashTableVector[token])
                TokenInfo = H[token]
                TokenInfo.append(tupla)
                H[token] = TokenInfo
print('ÍNDICE INVERTIDO')
for token in H:
    TokenInfo = H[token]
    M = len(TokenInfo) - 1
    idf = math.log(N/M)
    #Computa o tamanho dos documento para 'token'
    I = idf
    for tokenOcurrence in TokenInfo:
            if type(tokenOcurrence) is tuple:
                C = tokenOcurrence[1]
                T = math.pow(I * C, 2)
                DOC_REFERENCE[tokenOcurrence[0]] += T

    TokenInfo[0] = idf
    H[token] = TokenInfo

for doc in DOC_REFERENCE:
    DOC_REFERENCE[doc] = math.sqrt(DOC_REFERENCE[doc])
    tuple = (DOCS_PATH[doc], DOC_REFERENCE[doc])
    DOC_REFERENCE[doc] = tuple


with open('doc_reference.json', 'w') as fp:
    json.dump(DOC_REFERENCE, fp)
    print('doc_reference.json CRIADO!')
with open('index.json', 'w') as fp:
    json.dump(H, fp)
print('index.json CRIADO!')


