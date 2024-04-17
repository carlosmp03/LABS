#include "Sequence.cpp"
#include <cassert>

void AsAppendAndPrepandTest(){
    ArraySequence<int> AS;
    AS.Append(2);
    AS.Prepend(1);
    assert(AS.GetLength() == 2);
    assert(AS.Get(0) == 1);
    assert(AS.Get(1) == 2);
}

void LsAppendAndPrepandTest(){
    ListSequence<int> LS;
    LS.Prepend(1);
    LS.Append(2);
    
   
    assert(LS.GetLength() == 2);
    assert(LS.Get(0) == 1);
    assert(LS.Get(1) == 2);
}

void TestsForConcatArrayList(){
    ArraySequence<int> AS1;
    ArraySequence<int> AS2;
    AS1.Append(1);
    AS2.Append(2);

    Sequence<int> * concatedAS = AS1.Concat(&AS2);
    assert(concatedAS->GetLength() == 2);
    assert(concatedAS->Get(0) == 1 && concatedAS->Get(1) == 2);
}

void TestsForConcatListSequence(){
    ListSequence<int> LS1;
    ListSequence<int> LS2;
    Sequence<int> * concatedLS;
    LS1.Append(1);
    LS1.Append(2);
    LS2.Append(3);
    LS2.Append(4);

    concatedLS = LS1.Concat(&LS2);
    assert(concatedLS->GetLength() == 4);
    assert(concatedLS->Get(0) == 1);
    assert(concatedLS->Get(1) == 2);
    assert(concatedLS->Get(2) == 3);
    assert(concatedLS->Get(3) == 4);
}

void SubSeqArraySeqTest(){
    ArraySequence<int> AS;
    Sequence<int> * subAS;
    AS.Append(1);
    AS.Append(2);
    AS.Append(3);
    AS.Append(4);

    subAS = AS.GetSubsequence(1, 2);

    assert(subAS->GetLength() == 2);
    assert(subAS->Get(0) == 2);
    assert(subAS->Get(1) == 3);
}

void SubSeqListSeqTest(){
    ListSequence<int> LS;
    Sequence<int> * subLS;
    LS.Append(0);
    LS.Append(1);
    LS.Append(2);
    LS.Append(3);

    subLS = LS.GetSubsequence(1, 3);

    assert(subLS->GetLength() == 3);
    assert(subLS->Get(0) == 1);
    assert(subLS->Get(1) == 2);
    assert(subLS->Get(2) == 3);
}

void InsertIntoArraySeqTest(){
    ArraySequence<int> AS;
    AS.Append(0);
    AS.Append(1);
    AS.Append(3);

    AS.InsertAt(2, 2);
    assert(AS.GetLength() == 4);
    assert(AS.Get(0) == 0);
    assert(AS.Get(1) == 1);
    assert(AS.Get(2) == 2);
    assert(AS.Get(3) == 3);
}

void InsertIntoListSeqTest(){
    ListSequence<int> LS;
    LS.Append(0);
    LS.Append(1);
    LS.Append(3);

    LS.InsertAt(2, 2);
    assert(LS.GetLength() == 4);
    assert(LS.Get(0) == 0);
    assert(LS.Get(1) == 1);
    assert(LS.Get(2) == 2);
    assert(LS.Get(3) == 3);
}



int main(){
    AsAppendAndPrepandTest();
    std::cout << "pass 1\n";
    LsAppendAndPrepandTest();
    std::cout << "pass 2\n";
    TestsForConcatArrayList();
    std::cout << "pass 3\n";
    TestsForConcatListSequence();
    std::cout << "pass 4\n";
    SubSeqArraySeqTest();
    std::cout << "pass 5\n";
    SubSeqListSeqTest(); 
    std::cout << "pass 6\n";
    InsertIntoArraySeqTest();
    std::cout << "pass 7\n";
    InsertIntoListSeqTest();
    std::cout << "pass 8\n";
    std::cout << "Alless Guttt!!!" << "\n";
}

