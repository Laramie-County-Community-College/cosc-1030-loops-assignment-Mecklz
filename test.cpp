#include <iostream>
#include <cctype>

// int main(){
//     char num = '1';
//     while(num != '0'){
//         std::cout << ":: ";
//         std::cin >> num;
//         if (isdigit(num)) {
//             std::cout << std::endl << static_cast<int>(num) << " is a number.";
//         } else{
//             std::cout << std::endl << static_cast<int>(num) << " is not a number.";
//         }
//         std::cout << std::endl << num;
//     }
        

//     return 0;
// }

int main() {
    int guess;
    // while (guess != 'q')
    std::cout << "Please pick a number from 1-100: ";
    std::cin >> guess;
    if (!static_cast<bool>(guess)) {
        std::cout << "It was false" << guess;
    }
}