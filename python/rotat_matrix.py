import pprint

def transpose(mat):
	mat = [[row[i] for row in mat]for i in range(0,len(mat[0]))]
	return mat


def exchangecol(mat):
	for i in range(0,len(mat)):
		mat[i][0],mat[i][len(mat[0])-1] = mat[i][len(mat[0])-1],mat[i][0]

	return mat


def exchangerow(mat):
    for i in range(0,len(mat[0])):
        mat[0][i],mat[len(mat)-1][i] = mat[len(mat)-1][i],mat[0][i]

    return mat


def rotateright(mat):
	mat1 = transpose(mat)
	mat1 = exchangecol(mat1)
	
	return mat1

def rotateleft(mat):
    mat1 = transpose(mat)
    mat1 = exchangerow(mat1)

    return mat1


mat = [[1, 2, 3],
       [4, 5, 6],
       [7, 8, 9]]

mat1 = rotateleft(mat)

mat2 = rotateright(mat)

pprint.pprint(mat1)
pprint.pprint(mat2)


"""
mat = transpose(mat)

mat = exchangecol(mat)

mat = exchangerow(mat)
	
pprint.pprint(mat)
"""



