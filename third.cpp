#include <iostream>
using namespace std;

/**
	Var 17 N 4
	4. Дана действительная квадратная матрица C порядка 7.
	Найти последовательность чисел 1 49 b b , ..., , получающуюся при
	чтении матрицы по спирали, как показано на рис. 1.41(спираль от левого нижнего угла против часовой)
*/

typedef enum moves {
    m_right,
    m_down,
    m_left,
    m_up,
    moves_cnt,
} moves_t;

/* currect pos incrementer */
static bool adder(int& pos, const int max){
    if(pos < max){
        pos++;
    } else if(pos > max){
        pos--;
    } else {
        return true;
    }
    return false;
}

/* currect increment x,y */
static bool next_coords(int& x, int& y, const int max, const moves_t move) {
	if(move == m_right || move == m_left){
        return adder(x, max);
    } else if(move == m_up || move == m_down){
        return adder(y, max);
    }
	return false;
}

/* init matrix and fill zeros */
static int** matrix_init(const int n){
    int** matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}

    /* fill zeros */
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void third_4(void) {
	int n;
	cin >> n;
	if (n < 7) {
		cout << "must be 7 <= n";
		return;
	}

    /* create matrix and array*/
	int **matrix = matrix_init(n);
    int * d_maxs = new int[(n*2)-1];

    /* our turn order */
    const moves_t directions[moves_cnt] = {m_right, m_up, m_left, m_down};
    
    /* fill maxs values for do spiral */
    int d_maxs_for_fill[4] = {n-1, 0, 0, n-2};
    for(int i = 0; i < (n*2)-1; i++){
        int index = i & 0x3;
        d_maxs[i] = d_maxs_for_fill[index];
        if(index == 0 || index == 3){
            d_maxs_for_fill[index]--;
        } else {
            d_maxs_for_fill[index]++;
        }
    }
	/* set start point */
    int x = 0, y = n-1;
    int imax = 0;
    int idirection = 0;

    /* fill spiral matrix */
	for (int i = 0; i < n*n; i++) {
		/** @todo: 
         * i don't 
         * I filling i value
         * may be need fill from console 
         * or
         * fill from matrix to array 
         */
        matrix[y][x] = i;
		if(next_coords(x, y, d_maxs[imax], directions[idirection])){
            if(imax < (n*2)-1){
                imax++;
            } else {
                break;
            }
            idirection = idirection < (moves_cnt - 1)? idirection + 1 : 0;
            /* get next coord when change idirection */
            next_coords(x, y, d_maxs[imax], directions[idirection]);
        }
	}

    /* print matrix after fill */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

    /* free matrix and array */
    delete[] d_maxs;
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}