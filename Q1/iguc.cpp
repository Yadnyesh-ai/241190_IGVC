#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int main() {

    // Take matrix input from user
    std::vector<std::vector<int>> matrix;
    std::string input;

    std::cout << "Enter the matrix row by row. Press Enter on a blank line to finish input.\n";

    while (true) {
        std::getline(std::cin, input);

        // Check if the input line is empty (user pressed Enter on a blank line)
        if (input.empty()) {
            break;
        }

        std::vector<int> row;
        std::stringstream ss(input);
        int value;

        // Read integers from the input line
        while (ss >> value) {
            row.push_back(value);
        }

        // Check if the row is not empty
        if (!row.empty()) {
            // If it's not the first row, check if the number of elements matches the previous rows
            if (!matrix.empty() && row.size() != matrix[0].size()) {
                std::cout << "Error: Number of elements in each row must be the same.\n";
                continue;
            }

            // Add the row to the matrix
            matrix.push_back(row);
        }
    }

///////////////////////////////////////////////////////////////////////////////////////////
    // update all 2s to 1s for calc
    for(auto& row : matrix){
        for(auto& elem :row){
            if(elem == 2){
                elem = 1;
            }
        }
    }

///////////////////////////////////////////////////////////////////////////////////////////
    
    std:: cout<<"starting point 3 is at coordinateds:";
    std::pair<int,int> start={-1,-1};
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == 3){
                std::cout<<"("<<i<<","<<j<<")"<<std::endl;
                start.first=i;
                start.second=j;
            }
        }
    }

    int innerup=4,innerdown=matrix.size()-5,innerleft=4,innerright=matrix[0].size()-5;
    
///////////////////////////////////////////////////////////////////////////////////////////
    std::cout<<start.first<<","<<start.second<<std::endl;
    if(start.first>=innerup&&start.first<=innerdown+3&&start.second>=1&&start.second<=3){
        for(int i=1;i<=3;i++){
            if(i!=start.second) matrix[start.first][i]=4;
        }
        for(int i=start.first-1;matrix[i][start.second]!=1;i--){
            matrix[i][start.second]=4;
        }
    }

///////////////////////////////////////////////////////////////////////////////////////////
    for(int i=1;i<=3;i++){
        for(int j=innerup;j<=innerdown+3;j++){
            if(matrix[j][i]==4){
                for(int k=j-1;matrix[k][i]!=1;k--){
                    matrix[k][i]=matrix[j][i]+1;
                }
            }
        }
    }

    for(int i=start.second;i<=3;i++){
        for(int j=start.first;j>=1;j--){
            if(matrix[j][i]==0){
                int dum=INT_MAX;
                for(int k=start.second;k<=3;k++){
                    if(matrix[j][k]<=dum&&matrix[j][k]!=0&&matrix[j][k]!=1){
                        dum=matrix[j][k];
                    }
                }
                matrix[j][i]=dum+1;
            }
        }
    }

    for(int j=1;j<=3;j++){
        for(int i=innerleft;i<=innerright+3;i++){
            if(matrix[j][i]==1){
                break;
            }
            if(matrix[j][i]==0){
                int dum=INT_MAX;
                for(int k=1;k<=3;k++){
                    if(matrix[j][k]<=dum&&matrix[j][k]!=0){
                        dum=matrix[j][k];
                    }
                }
                matrix[j][i]=dum+1;
            }
        }
    }

    for(int i=1;i<=3;i++){
        for(int j=innerleft;j<=innerright+3;j++){
            if(matrix[i][j]==0){
                int dum=INT_MAX;
                for(int k=1;k<=3;k++){
                    if(matrix[k][j]<=dum&&matrix[k][j]!=0&&matrix[k][j]!=1){
                        dum=matrix[k][j];
                    }
                }
                matrix[i][j]=dum+1;
            }
        }
    }
    
    // for(int i=innerright+1;i<=innerright+3;i++){
    //     for(int j=innerup;j<=innerdown+3;j++){
    //         if(matrix[j][i]==1){
    //             break;
    //         }
    //         if(matrix[j][i]==0){
    //             int dum=INT_MAX;
    //             for(int k=1;k<=3;k++){
    //                 if(matrix[j][k]<=dum&&matrix[j][k]!=0){
    //                     dum=matrix[j][k];
    //                 }
    //             }
    //             matrix[j][i]=dum+1;
    //         }
    //     }
    // }
//////////////////////////////////////////////////////////////////////////////////////////

    // Display the matrix
    std::cout << "The matrix you entered is:\n";
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
    return 0;
}