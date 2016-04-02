//
// Created by Omar Shaikh on 2/8/16.
//

#include "gtest/gtest.h"
#include "DLinkedStack.h"
#include <math.h>
#include <vector>

using namespace std;

int points = 100;
int currentPoints = 0;

template<class T>
bool equalVectors(vector<T> a, vector<T> b) {
    a.shrink_to_fit();
    b.shrink_to_fit();
    if (a.size() != b.size()) return false;
    else {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return false;
        }

    }
    return true;
}

TEST(hw5Test, basicConstructorTest) {

    DLinkedStack<int> basicStack;

    if (HasFailure()) { cerr << "basicConstructorTest has failed" << endl; }

}

TEST(hw5Test, constructorTest) {

    DLinkedStack<int> basicStack;

    EXPECT_TRUE(basicStack.isEmpty()) << "Expected Stack empty" << endl;
    ASSERT_EQ(basicStack.getPointerTo(55), nullptr) << "Expected nullptr from getPointerTo()" << endl;

    if (HasFailure()) { cerr << "constructorTest has failed" << endl; }

}

TEST(hw5Test, addToStackTest) {

    DLinkedStack<int> basicStack;
    basicStack.push(88);
    basicStack.push(44);

    vector<int> vector1 = basicStack.toVector();
    vector<int> vector2{44, 88};

    EXPECT_TRUE(equalVectors(vector1, vector2));


    if (HasFailure()) {
        points -= 15;
        cerr << "addToStackTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    } else {
        currentPoints += 15;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw5Test, copyConstructorTest) {

    DLinkedStack<int> basicStack;
    basicStack.push(88);
    basicStack.push(44);
    vector<int> vector1 = basicStack.toVector();
    vector<int> vector2{44, 88};
    EXPECT_TRUE(equalVectors(vector1, vector2));

    DLinkedStack<int> basicStack2 = basicStack;

    vector<int> vector3 = basicStack2.toVector();
    EXPECT_TRUE(equalVectors(vector1, vector3));


    if (HasFailure()) {
        points -= 10;
        cerr << "copyConstructorTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    } else {
        currentPoints += 10;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw5Test, emptyTest) {

    DLinkedStack<int> basicStack;

    EXPECT_TRUE(basicStack.isEmpty());
    basicStack.push(44);
    basicStack.push(88);

    EXPECT_FALSE(basicStack.isEmpty());


    if (HasFailure()) {
        points -= 5;
        cerr << "emptyTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    } else {
        currentPoints += 5;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}


TEST(hw5Test, removeTest) {

    DLinkedStack<int> basicStack;
    basicStack.push(44);
    basicStack.push(88);

    basicStack.pop();
    vector<int> vector1 = basicStack.toVector();
    vector<int> vector2{44};
    EXPECT_FALSE(basicStack.isEmpty());
    EXPECT_TRUE(equalVectors(vector1, vector2));


    if (HasFailure()) {
        points -= 10;
        cerr << "removeTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    }
    else {
        currentPoints += 10;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw5Test, headTest) {

    DLinkedStack<int> basicStack;
    basicStack.push(44);
    basicStack.push(88);
    basicStack.push(66);
    basicStack.push(88);
    basicStack.push(88);
    basicStack.pop();
    EXPECT_FALSE(basicStack.isEmpty());

    Node<int> *head = basicStack.getHeadPTR();
    Node<int> *node = basicStack.getPointerTo(44);

    ASSERT_NE(node, nullptr);

    EXPECT_EQ(node->getPrev(), nullptr);
    EXPECT_EQ(node, head);

    if (HasFailure()) {
        points -= 20;
        cerr << "headTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    }
    else {
        currentPoints += 20;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw5Test, topTest) {

    DLinkedStack<int> basicStack;
    basicStack.push(44);
    basicStack.push(88);
    basicStack.push(66);
    basicStack.push(88);
    basicStack.push(99);
    basicStack.push(999);
    EXPECT_FALSE(basicStack.isEmpty());

    Node<int> *top = basicStack.getTopPTR();
    Node<int> *node = basicStack.getPointerTo(999);

    ASSERT_NE(node, nullptr);

    EXPECT_EQ(node->getNext(), nullptr);

    EXPECT_EQ(node, top);

    if (HasFailure()) {
        points -= 20;
        cerr << "topTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
    }
    else {
        currentPoints += 20;
        cout << "Current POINTS:" << currentPoints << endl;
    }

}

TEST(hw5Test, midTest) {

    DLinkedStack<int> basicStack;
    basicStack.push(44);
    basicStack.push(88);
    basicStack.push(55);
    basicStack.push(66);
    basicStack.push(77);
    basicStack.push(88);
    basicStack.push(99);
    basicStack.push(999);


    EXPECT_FALSE(basicStack.isEmpty());

    Node<int> *node = basicStack.getPointerTo(55);
    Node<int> *node2 = basicStack.getPointerTo(66);
    Node<int> *node3 = basicStack.getPointerTo(77);

    ASSERT_NE(node, nullptr);
    ASSERT_NE(node2, nullptr);
    ASSERT_NE(node3, nullptr);


    EXPECT_EQ(node->getNext(), node2);
    EXPECT_EQ(node2->getNext(), node3);
    EXPECT_EQ(node2->getPrev(), node);
    EXPECT_EQ(node3->getPrev(), node2);

    if (HasFailure()) {
        points -= 20;
        cerr << "midTest has failed" << endl;
        cout << "Current POINTS:" << currentPoints << endl;
        cout << "FINAL POINTS:" << points << endl;
    } else {
        currentPoints += 20;
        cout << "Current POINTS:" << currentPoints << endl;
    }

    cout << "FINAL POINTS:" << points << endl;

}
