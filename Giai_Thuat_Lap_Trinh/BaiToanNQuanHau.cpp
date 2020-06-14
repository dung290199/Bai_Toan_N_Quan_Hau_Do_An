#include <iostream>
#include <string>
using namespace std;

int** board;
int n;

void init(){
	board = new int*[n];
    for(int i = 0; i < n; i++)
        board[i] = new int[n];
        
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		board[i][j] = 0;
		}
	}
        
}

void display(){
	for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		cout << board[i][j] << " ";	
		}
        cout << endl;
	}
}

bool check(int row, int col){
	int i, j;
	
	for(int i = 0; i < col; i++){
		if (board[row][i]){
			return false;
		}
	}
	
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    for (i = row, j = col; j >= 0 && i < n; i++, j--) 
        if (board[i][j]) 
            return false; 
            
	return true;
}

bool tryIt(int col){
	if (col >= n){
		return true;
	}
	for(int row = 0; row < n; row++){
		if(check(row, col)){
			board[row][col] = 1;
			if (tryIt(col + 1)){
				return true;
			} else{
				board[row][col] = 0;
			}
		}
	}
	return false;
}

void clear(){
	for(int i = 0; i < n; i++){
		delete[] board[i];
	}

    delete[] board;
}

int main()
{
	string cons = "";
    do{
    	do {
			cout << "Nhap so quan hau: ";
    		cin >> n;	
    		if (n < 4) {
    			cout << "So quan hau phai tu 4 quan tro len" << endl ;
			}
		} while(n < 4);
		
    	init();
    	tryIt(0);
    	display();	
    	clear();
    	cout << "Ban co muon tiep tuc?(Y/N)";
    	cin >> cons;
    	cout << endl;
	} while (cons == "Y" || cons == "y");
    
    return 0;
}
