from nltk.tokenize import sent_tokenize

# Helpful source: https://stackoverflow.com/questions/19007383/compare-two-different-files-line-by-line-in-python

def lines(a, b):
    """Return lines in both a and b"""
    a = set(a.split('\n'))
    b = set(b.split('\n'))
    return list(a.intersection(b))


def sentences(a, b):
    """Return sentences in both a and b"""
    a = set(sent_tokenize(a))
    b = set(sent_tokenize(b))
    return list(a.intersection(b))


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    a = set([a[sub:sub + n] for sub in range(len(a) - n + 1)])
    b = set([b[sub:sub + n] for sub in range(len(b) - n + 1)])
    return list(a.intersection(b))
