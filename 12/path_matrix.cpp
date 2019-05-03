#include<iostream>
#include <cstring>
using namespace std;
//打印matrix
void print_matrix(const char* matrix, int rows, int cols){
	for(int i=0; i<rows; ++i){
		for(int j=0; j<cols; ++j){
			cout << matrix[i*cols+j] << " ";
		}
		cout << endl;
	}
}

bool has_path_core(const char* matrix, int rows, int cols, const char* str, int row, int col, int &path_length, bool* visited){
	if(str[path_length]=='\0')
		return true;
	bool has=false;
	//扩展枝条
	if(row>=0&&row<rows && col>=0&&col<cols && matrix[row*cols+col]==str[path_length] && !visited[row*cols+col]){
		//更新全局变量
		++path_length;
		visited[row*cols+col]=true;

		has=has_path_core(matrix, rows, cols, str, row-1, col, path_length, visited) ||
			has_path_core(matrix, rows, cols, str, row, col-1, path_length, visited) ||
			has_path_core(matrix, rows, cols, str, row+1, col, path_length, visited) || 
			has_path_core(matrix, rows, cols, str, row, col+1, path_length, visited);

		//回溯,恢复全局量
		if(!has){
			--path_length;
			visited[row*cols+col]=false;
		}
	}
	return has;
}

bool has_path(const char* matrix, int rows, int cols, const char* str){
	if(matrix==nullptr || rows<1 || cols<1 || str==nullptr)
		return false;

	bool* visited=new bool[rows*cols];
	memset(visited, false, rows*cols);

	int path_length=0;
	for(int row=0; row<rows; ++row){
		for(int col=0; col<cols; ++col){
			if(has_path_core(matrix, rows, cols, str, row, col, path_length, visited))
				return true;
		}
	}

	delete[] visited;
	return false;
}


int main(){
	// char matrix[] = "abtgcfcsjdeh";
	// char str[]= "bfcef";

	// const char* matrix = "ABTGCFCSJDEH";
 //    const char* str = "BFCE";

    // const char* matrix = "ABCESFCSADEE";
    // const char* str = "SEE";

    // const char* matrix = "ABTGCFCSJDEH";
    // const char* str = "ABFB";

    // const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    // const char* str = "SLHECCEIDEJFGGFIE";

    // const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    // const char* str = "SGGFIECVAASABCEHJIGQEM";

    // const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    // const char* str = "SGGFIECVAASABCEEJIGOEM";

    // const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    // const char* str = "SGGFIECVAASABCEHJIGQEMS";

    // const char* matrix = "AAAAAAAAAAAA";
    // const char* str = "AAAAAAAAAAAA";

    // const char* matrix = "AAAAAAAAAAAA";
    // const char* str = "AAAAAAAAAAAAA";

    // const char* matrix = "A";
    // const char* str = "A";

    const char* matrix = "A";
    const char* str = "B";

	//int rows=3, cols=4;
    //int rows=5, cols=8;
    int rows=1, cols=1;
	print_matrix(matrix, rows, cols);
	cout << str << endl;
	cout << "is it has? " << has_path(matrix, rows, cols, str) << endl; 
	return 0;
}









