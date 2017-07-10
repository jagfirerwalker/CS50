import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        self.positives = set()
        
        # open file that has been passed on, for reading
        file = open(positives, "r")
        
        # go through it line by line and remove the "\n" or enter, check if the line starts with a letter
        # and then add it to the set if it does.
        for line in file:
            word = line.strip("\n")
            if word[:1].isalpha():
                self.positives.add(word)
        file.close()
        
        # create a new set for netive    
        self.negatives = set()
        
        # open the file that hold the native word list ad itereate over it
        file = open(negatives, "r")
        for line in file:
            word = line.strip("\n")
            if word[:1].isalpha():
                self.negatives.add(word)
        file.close()
        
        
        
    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        # crate world list from the entered text
        positive, negative, neutral = 0.0, 0.0, 0.0
        
        # for words in words (if multiple) check if words
        # is in positive or negative and add value
        for word in (list(text)):
            
            word = word.lower()
            if word in self.positives:
                positive += 1
            elif word in self.negatives:
                negative += 1
            else:
                neutral += 1
                
        return positive, negative, neutral
