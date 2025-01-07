class Solution:
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        row1 = set("qwertyuiop")
        row2 = set("asdfghjkl")
        row3 = set("zxcvbnm")
        output_words = []
        for myword in words:
            word_set = set(myword.lower())
            if word_set.issubset(row1) or word_set.issubset(row2) or word_set.issubset(row3):
                output_words.append(myword)
        return output_words