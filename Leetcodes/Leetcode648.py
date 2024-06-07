class Solution(object):
    def replaceWords(self, dictionary, sentence):
        s=sentence.split(' ')
        d=dictionary
        ss=''

        for i in range(len(s)):
            for j in d:
                l=len(j)
                if s[i][0:l] == j:
                    s[i] =j
        for i in s:
            ss+=i+' '
            
        return ss.strip()
                