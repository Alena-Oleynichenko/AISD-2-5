#include <iostream>
#include <time.h>
#include "Header.h"
#include <math.h>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;


int GetKey()
{
    int key = _getch();
    if ((key == 0) || (key == 224)) key = _getch();
    return key;
}

int Menu_()
{
    system("cls");
    cout << "Choose type of elements:\n\n 1- bool\n 2-int\n 3-char\n 4-an example of working with the enum class\n\n Esc - Exit\n";
    while (true)
    {
        int key = GetKey();
        if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52)) return key;
    }
}

int Menu()
{
    system("cls");
    cout << "1 - Watch examples\n2 - Creating image\n3 - Try out methods\n\nEsc - Back\n ";
    while (true)
    {
        int key = GetKey();
        if ((key == 27) || (key == 49) || (key == 50) || (key == 51)) return key;
    }
}

int Menu_1()
{
    system("cls");

    cout << "1 - Replacing an element in an image 1 \n2 - im1+im2\n3 - im1*im2\n4 - !im1\n5 - im3+1\n6 - im1*1\n7 - Fullness of im2\n8 - im3=im1\n\n Esc - Back" << std::endl;
    while (true)
    {
        int key = GetKey();
        if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56)) return key;
    }
}


int Menu2()
{
    cout << "Yes -  Enter\nNo - Esc\n";
    while (true)
    {
        int key = GetKey();
        if ((key == 27) || (key == 13)) return key;
    }
}


int main() {
    srand(time(0));

    int  answer = Menu_();
    while (answer != 27) {
        image<bool, 1, 0> image1(5, 5), image2(5, 5), image3(5, 5), image4(3, 3);
        image1.random(); image2.random(); image3.random();
        image<int, 7, 4> image5(5, 5), image6(5, 5), image7(5, 5), image8(3, 3);
        image5.random(); image6.random(); image7.random();
        image<char, 'S', 'N'> image9(5, 5), image10(5, 5), image11(5, 5), image12(3, 3);
        image9.random(); image10.random(); image11.random();
        switch (answer)
        {
        case 49:
            cout << " Working with bool type\n\n";

            while (true) {
                int  answer = Menu();
                while (answer != 27) {
                    switch (answer)
                    {
                    case 49:
                        try {

                            cout << "\n""Images for tests:\n\n";
                            cout << "1.\n";
                            image1.print();

                            cout << "\n[Test]\n" << "Reverse image:\n";
                            (!image1).print();

                            system("pause"); cout << "next\n";

                            cout << "\n[Test1]\n" << "Summing up images:\n";
                            cout << "1.\n";
                            image1.print();
                            cout << "2.\n";
                            image2.print();

                            cout << "\n1+2:\n" << endl;
                            (image1 + image2).print();

                            system("pause"); cout << "next\n";

                            cout << "\n[Test2]\n" << "The product of images:\n";
                            cout << "2.\n";
                            image2.print();
                            cout << "3.\n";
                            image3.print();

                            cout << "2*3:\n";
                            (image3 * image2).print();

                            system("pause"); cout << "next\n";

                            cout << "\n[Test3]\n" << "Fullness of image:\n";
                            cout << "3.\n";
                            image3.print();
                            cout << image3.coefficient();

                        }
                        catch (const char* exception)
                        {
                            cout << exception << '\n';
                        }
                        break;


                    case 50:

                        try {
                            cout << "\nimage1: \n";
                            cout << "\nYou have image the size 3 * 3, fill it in pixels: 1- true, 0- false\n";
                            image4.draw();
                            image4.print();

                            cout << "\nFullness of image:\n";
                            cout << image4.coefficient();
                        }
                        catch (const char* exception)
                        {
                            cout << exception << '\n';
                        }

                        break;

                    case 51:
                        answer = Menu_1();
                        int i = 0, j = 0, val = 0;
                        if (answer == 13) break;
                        try {
                            switch (answer)
                            {
                            case 49:
                                cout << "\n\n1.\n";
                                image1.print();

                                cout << "\nwhich element to replace:\n\nWhat row?\n";
                                cin >> i;
                                cout << "\nWhat column?\n";
                                cin >> j;
                                cout << "\nWhat value?\n";
                                cin >> val;
                                if ((i >= 5) || (j >= 5) || (i < 0) || (j < 0) || ((val != 0) && (val != 1))) throw "exeption";
                                else image1.SetMij(i, j, val);
                                image1.print();
                                break;

                            case 50:
                                cout << "\n\n1.\n";
                                image1.print();
                                cout << "2.\n";
                                image2.print();
                                cout << "1+2.\n";
                                (image1 + image2).print();
                                break;

                            case 51:
                                cout << "\n\n1.\n";
                                image1.print();
                                cout << "2.\n";
                                image2.print();
                                cout << "1*2.\n";
                                (image1 * image2).print();
                                break;
                            case 52:
                                cout << "\n\n1.\n";
                                image1.print();
                                cout << "!1.\n";
                                (!image1).print();
                                break;
                            case 53:
                                cout << "\n\n3.\n";
                                image1.print();
                                cout << "3.+1\n";
                                (image3 + 1).print();
                                break;
                            case 54:
                                cout << "\n\n1.\n";
                                image1.print();
                                cout << "1.*2\n";
                                (image1 * 2).print();
                                break;
                            case 55:
                                cout << "2.\n";
                                image2.print();
                                cout << "2.Fullness of image:\n";
                                cout << image2.coefficient();
                                break;
                            case 56:
                                cout << "\n\n1.\n";
                                image1.print();
                                cout << "3.\n";
                                image3.print();
                                cout << "3=1.\n";
                                (image3 = image1).print();
                                break;
                            }

                        }
                        catch (const char* exception)
                        {
                            cout << exception << '\n';
                        }
                        break;
                    }
                    cout << "\nagain?";
                    answer = Menu2();
                }
            }
            break;
           
        case 50:
            while (true) {
                int  answer = Menu();
                while (answer != 27) {
                    switch (answer)
                    {
                    case 49:
                        try {
                            cout << "Images for tests:\n\n";
                            cout << "1.\n";
                            image5.print();
                            cout << "\n[Test]\n" << "Reverse image:\n";
                            (!image5).print();
                            system("pause"); cout << "next\n";
                            cout << "\n[Test1]\n" << "Summing up images:\n";
                            cout << "1.\n";
                            image5.print();
                            cout << "2.\n";
                            image6.print();
                            cout << "\n1+2:\n" << endl;
                            (image5 + image6).print();
                            system("pause"); cout << "next\n";
                            cout << "\n[Test2]\n" << "The product of images:\n";
                            cout << "2.\n";
                            image6.print();
                            cout << "3.\n";
                            image7.print();
                            cout << "2*3:\n";
                            (image7 * image6).print();
                            system("pause"); cout << "next\n";
                            cout << "\n[Test3]\n" << "Fullness of image:\n";
                            cout << "3.\n";
                            image7.print();
                            cout << image7.coefficient();
                        }
                        catch (const char* exception) // обработчик исключений типа const char*
                        {
                            cout << exception << '\n';
                        }
                        break;
                    case 50:

                        try {
                            cout << "\n image1: \n";
                            cout << "\nYou have image the size 3 * 3, fill it in pixels: 7- true, 4- false\n";
                            image8.draw();
                            image8.print();

                            cout << "\nFullness of image:\n";
                            cout << image8.coefficient();
                            
                        }
                        catch (const char* exception) 
                        {
                            cout << exception << '\n';
                        }

                        break;

                    case 51:
                        answer = Menu_1();
                        int i = 0, j = 0, val = 0;
                        if (answer == 27) break;
                        try {
                            switch (answer)
                            {
                            case 49:
                                cout << "\n\n1.\n";
                                image5.print();

                                cout << "\nwhich element to replace:\n\nWhat row?\n";
                                cin >> i;
                                cout << "\nWhat column?\n";
                                cin >> j;
                                cout << "\nWhat value?\n";
                                cin >> val;
                                if ((i >= 5) || (j >= 5) || (i < 0) || (j < 0) || ((val != 0) && (val != 1))) throw "exeption";
                                else image5.SetMij(i, j, val);
                                image5.print();
                                break;

                            case 50:
                                cout << "\n\n1.\n";
                                image5.print();
                                cout << "2.\n";
                                image6.print();
                                cout << "1+2.\n";
                                (image5 + image6).print();
                                break;

                            case 51:
                                cout << "\n\n1.\n";
                                image5.print();
                                cout << "2.\n";
                                image6.print();
                                cout << "1*2.\n";
                                (image5 * image6).print();
                                break;
                            case 52:
                                cout << "\n\n1.\n";
                                image5.print();
                                cout << "!1.\n";
                                (!image5).print();
                                break;
                            case 53:
                                cout << "\n\n3.\n";
                                image7.print();
                                cout << "3.+1\n";
                                (image7 + 1).print();
                                break;
                            case 54:
                                cout << "\n\n1.\n";
                                image5.print();
                                cout << "1.*2\n";
                                (image5 * 2).print();
                                break;
                            case 55:
                                cout << "2.\n";
                                image6.print();
                                cout << "2.fullness\n";
                                cout << image6.coefficient();
                                break;
                            case 56:
                                cout << "\n\n1.\n";
                                image5.print();
                                cout << "3.\n";
                                image7.print();
                                cout << "3=1.\n";
                                (image7 = image5).print();
                                break;
                            }

                        }
                        catch (const char* exception) 
                        {
                            cout << exception << '\n';
                        }
                        break;
                    }
                    cout << "\nagain?";
                    answer = Menu2();
                }
            }
            break;
        case 51:
            cout << " Working with char type\n\n";
            while (true)
            {
                int  answer = Menu();
                while (answer != 13) {
                    switch (answer) {
                    case 49:
                        try {
                            cout << "Images for tests:\n\n";
                            cout << "1.\n";
                            image9.print();
                            cout << "\n[Test]\n" << "Reverse image:\n";
                            (!image9).print();
                            system("pause"); cout << "next\n";
                            cout << "\n[Test1]\n" << "Summing up images:\n";
                            cout << "1.\n";
                            image9.print();
                            cout << "2.\n";
                            image10.print();
                            cout << "\n1+2:\n" << endl;
                            (image9 + image10).print();
                            system("pause"); cout << "next\n";
                            cout << "\n[Test2]\n" << "The product of images:\n";
                            cout << "2.\n";
                            image10.print();
                            cout << "3.\n";
                            image11.print();
                            cout << "2*3:\n";
                            (image11 * image10).print();
                            system("pause"); cout << "next\n";
                            cout << "\n[Test3]\n" << "Fullness of image:\n";
                            cout << "3.\n";
                            image11.print();
                            cout << image11.coefficient();
                        }
                        catch (const char* exception) 
                        {
                            cout << exception << '\n';
                        }
                        break;
                    case 50:

                        try {
                            cout << "\nimage1: \n";
                            cout << "\n You have image the size 3 * 3, fill it in pixels: S- true, N- false\n";
                            image12.draw();
                            image12.print();

                            cout << "\nFullness of image:\n";
                           cout << image12.coefficient();
                        }
                        catch (const char* exception) 
                        {
                            cout << exception << '\n';
                        }

                        break;

                    case 51:
                        answer = Menu_1();
                        int i = 0, j = 0, val = 0;
                        if (answer == 13) break;
                        try {
                            switch (answer)
                            {
                            case 49:
                                cout << "\n\n1.\n";
                                image9.print();

                                cout << "\nwhich element to replace:\n\nWhat row?\n";
                                cin >> i;
                                cout << "\nWhat column?\n";
                                cin >> j;
                                cout << "\nWhat value?\n";
                                cin >> val;
                                if ((i >= 5) || (j >= 5) || (i < 0) || (j < 0) || ((val != 0) && (val != 1))) throw "exeption";
                                else image9.SetMij(i, j, val);
                                image9.print();
                                break;

                            case 50:
                                cout << "\n\n1.\n";
                                image9.print();
                                cout << "2.\n";
                                image10.print();
                                cout << "1+2.\n";
                                (image9 + image10).print();
                                break;

                            case 51:
                                cout << "\n\n1.\n";
                                image9.print();
                                cout << "2.\n";
                                image2.print();
                                cout << "1*2.\n";
                                (image9 * image10).print();
                                break;
                            case 52:
                                cout << "\n\n1.\n";
                                image9.print();
                                cout << "!1.\n";
                                (!image9).print();
                                break;
                            case 53:
                                cout << "\n\n3.\n";
                                image9.print();
                                cout << "3.+1\n";
                                (image11 + 1).print();
                                break;
                            case 54:
                                cout << "\n\n1.\n";
                                image9.print();
                                cout << "1.*2\n";
                                (image9 * 2).print();
                                break;
                            case 55:
                                cout << "2.\n";
                                image10.print();
                                cout << "2.fullness\n";
                                cout << image10.coefficient();
                                break;
                            case 56:
                                cout << "\n\n1.\n";
                                image9.print();
                                cout << "3.\n";
                                image11.print();
                                cout << "3=1.\n";
                                (image11 = image9).print();
                                break;
                            }

                        }
                        catch (const char* exception) 
                        {
                            cout << exception << '\n';
                        }
                        break;
                    }
                }
                cout << "\nagain?";
                answer = Menu2();

            }
            break;
            
        case 52:
            cout << "\n Working with enum\n";
            image<CardinalDirection, CardinalDirection::EAST, CardinalDirection::WEST> image12(5, 5);                    
            cout << "\nImage 1:\n";
            image12.print();
            cout << "\nChange elements on plaeces 1x1 and 1x3\n";
            image12.SetMij(1,1, CardinalDirection::WEST);
            image12.SetMij(1, 3, CardinalDirection::EAST);
            cout << "New image 1:\n";
            image12.print();                   
            answer = Menu2();              
            if (answer == 27) break;
        }
    }
}