def LCS(S):
    n = len(S)
    S += S     
	# Concatenate string to 
	# self to avoid modular arithmetic
    f = [-1 for c in S]   
	# Failure function
    k = 0       
	# Least rotation of string found so far
    for j in range(1, 2*n):
        i = f[j-k-1]
        while i != -1 and S[j] != S[k+i+1]:
            if S[j] < S[k+i+1]:
                k = j-i-1
            i = f[i]
        if i == -1 and S[j] != S[k+i+1]:
            if S[j] < S[k+i+1]:
                k = j
            f[j-k] = -1
        else:
            f[j-k] = i+1
    return k