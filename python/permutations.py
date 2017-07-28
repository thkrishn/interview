def permut(word):
	if len(word) == 1:
		return word

	words = permut(word[1:])
	char = word[0]
	result = []

	for word in words:
		for i in range(0,len(word)+1):
			result.append(word[:i]+char+word[i:])
	
	return result
		


print permut("ACT")