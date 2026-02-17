#include <iostream>

#include "../include/card_game/core/data_structures/linked_list/LinkedList.h"

void showMenu()
{
    std::cout << "\n==== MENU LINKED LIST ====\n";
    std::cout << "1. Add First\n";
    std::cout << "2. Add Last\n";
    std::cout << "3. Add At Position\n";
    std::cout << "4. Remove First\n";
    std::cout << "5. Remove Last\n";
    std::cout << "6. Remove At Position\n";
    std::cout << "7. Get At Position\n";
    std::cout << "8. Get Size\n";
    std::cout << "9. Is Empty\n";
    std::cout << "10. Print List\n";
    std::cout << "0. Exit\n";
    std::cout << "Select option: ";
}


int main()
{
    LinkedList<int> list;
    int option = -1;

    while (option != 0)
    {
        showMenu();
        std::cin >> option;

        try
        {
            switch (option)
            {
            case 1:
                {
                    int value;
                    std::cout << "Value: ";
                    std::cin >> value;
                    list.addFirst(value);
                    break;
                }

            case 2:
                {
                    int value;
                    std::cout << "Value: ";
                    std::cin >> value;
                    list.addLast(value);
                    break;
                }

            case 3:
                {
                    int value, pos;
                    std::cout << "Value: ";
                    std::cin >> value;
                    std::cout << "Position: ";
                    std::cin >> pos;
                    list.addAt(value, pos);
                    break;
                }

            case 4:
                list.removeFirst();
                break;

            case 5:
                list.removeLast();
                break;

            case 6:
                {
                    int pos;
                    std::cout << "Position: ";
                    std::cin >> pos;
                    list.removeAt(pos);
                    break;
                }

            case 7:
                {
                    int pos;
                    std::cout << "Position: ";
                    std::cin >> pos;
                    auto node = list.getAt(pos);
                    std::cout << "Value: " << list.getContent(node) <<

                        std::endl;
                    break;
                }

            case 8:
                std::cout << "Size: " << list.getSize() << std::endl;
                break;

            case 9:
                std::cout << (list.isEmpty()
                                  ? "List is empty\n"
                                  : "List is NOT empty\n");
                break;

            case 10:
                {
                    SimpleNode<int>* current = list.getHead();
                    while (current != nullptr)
                    {
                        std::cout << current->value() << " -> ";
                        current = current->next();
                    }
                    std::cout << "nullptr\n";
                    break;
                }

            case 0:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid option\n";
            }
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
