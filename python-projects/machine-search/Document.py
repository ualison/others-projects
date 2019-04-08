from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.stem import PorterStemmer
import re


class Document:
    ID = 0
    nameDocument = ''
    diretoryFile = ''
    textStringDocument = {}

    def __init__(self, id, namedocument, dirfile):
        self.ID = id
        self.nameDocument = namedocument
        self.diretoryFile = dirfile + namedocument

    def getID(self) -> int:
        return self.ID

    def getnamedocument(self) -> str:
        return self.nameDocument

    def getdiretoryfile(self) -> str:
        return self.diretoryFile

    def gettextstringdocument(self) -> {}:
        return self.textStringDocument

    def to_vector(self) -> dict:
        ref_arquivo = open(self.diretoryFile, "r", encoding='utf8')

        string = ref_arquivo.read()

        string = re.sub('[^A-Za-z]+', ' ',string)
        ref_arquivo.close()

        stop_words = set(stopwords.words('english'))
        tokens = word_tokenize(string.lower())

        ps = PorterStemmer()

        hashTableVector = dict()
        maxFreq = 0
        for w in tokens:
            if w not in stop_words:
                count = tokens.count(w)
                if count > maxFreq:
                    maxFreq = count
                w = ps.stem(w)
                #tf = float(count / maxFreq) - NORMALIZAR
                hashTableVector[w] = count
        return hashTableVector
