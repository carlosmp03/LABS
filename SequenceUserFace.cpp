#include <iostream>
#include "Sequence.cpp"

template<typename T>
void ArraySequenceFace(ArraySequence<T>* sequence) {
    int choice;
    T val;
    int index, startIndex, endIndex;
    ArraySequence<T>* subseq;
    ArraySequence<T>* concated;

    while (choice != 7) {
        std::cout << "\nChoose an operation:\n"
                  << "1. Append element to the end\n"
                  << "2. Prepend element to the start\n"
                  << "3. Insert element at index\n"
                  << "4. Print the sequence\n"
                  << "5. Get subseq\n"
                  << "6. Concatenate sequence with itself\n"
                  << "7. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter element to append: ";
                std::cin >> val;
                sequence->Append(val);
                break;
            case 2:
                std::cout << "Enter element to prepend: ";
                std::cin >> val;
                sequence->Prepend(val);
                break;
            case 3:
                std::cout << "Enter index and element to insert: ";
                std::cin >> index >> val;
                sequence->InsertAt(val, index);
                break;
            case 4:
                sequence->Print();
                break;
            case 5:
                std::cout << "Enter start index and end index for the subseq: ";
                std::cin >> startIndex >> endIndex;
                subseq = static_cast<ArraySequence<T>*>(sequence->GetSubsequence(startIndex, endIndex));
                subseq->Print();
                delete subseq; 
                break;
            case 6:
                concated = static_cast<ArraySequence<T>*>(sequence->Concat(sequence)); 
                concated->Print();
                delete concated; 
                break;
            case 7:
                std::cout << "Exiting...\n";
                return;
            default:
                std::cout << "Invalid choice, try again.\n";
                break;
        }
    }
}

template <typename T>
void LinkedListSeqFace(ListSequence<T> * sequence){
    int choice;
    T val;
    int index, startIndex, endIndex;
    ListSequence<T> * concated;
    ListSequence<T> * subseq;

    while (choice != 7) {
        std::cout << "\nChoose an operation:\n"
                  << "1. Append element to the end\n"
                  << "2. Prepend element to the start\n"
                  << "3. Insert element at index\n"
                  << "4. Print the sequence\n"
                  << "5. Get subseq\n"
                  << "6. Concatenate sequence with itself\n"
                  << "7. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter element to append: ";
                std::cin >> val;
                sequence->Append(val);
                break;
            case 2:
                std::cout << "Enter element to prepend: ";
                std::cin >> val;
                sequence->Prepend(val);
                break;
            case 3:
                std::cout << "Enter index and element to insert: ";
                std::cin >> index >> val;
                sequence->InsertAt(val, index);
                break;
            case 4:
                sequence->Print();
                break;
            case 5:
                std::cout << "Enter start index and end index for the subseq: ";
                std::cin >> startIndex >> endIndex;
                subseq = static_cast<ListSequence<T>*>(sequence->GetSubsequence(startIndex, endIndex));
                subseq->Print();
                delete subseq; 
                break;
            case 6:
                concated = static_cast<ListSequence<T>*>(sequence->Concat(sequence)); 
                concated->Print();
                delete concated; 
                break;
            case 7:
                std::cout << "Exiting...\n";
                return;
            default:
                std::cout << "Invalid choice, try again.\n";
                break;
        }
    }
}

void SeqFace(){
    ArraySequence<int> sequence1; 
    ListSequence<int> sequence2;
    int choice;
    
    while (choice != 3){
        std::cout << "\nChoose between ArraySequence and ListSequence:\n"
              << "1. ArraySequence.\n"
              << "2. ListSequnce.\n"
              << "3. Exit.\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            ArraySequenceFace(&sequence1);
            break;
        case 2:
            LinkedListSeqFace(&sequence2);
            break;
        case 3:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Oops! Invalid choice! Please try again!";
            break;
        }
    }
}

int main() {
    SeqFace();
    return 0;
}
