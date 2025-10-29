#include <gtest/gtest.h>
#include "stack.h"

class ArrayStackTest : public ::testing::Test {
protected:
    ArrayStack stack;
    
    void SetUp() override {
        createArrayStack(&stack);
    }
};

class ListStackTest : public ::testing::Test {
protected:
    ListStack stack;
    
    void SetUp() override {
        createListStack(&stack);
    }
    
    void TearDown() override {
        // Очищаем память, выделенную для узлов списка
        while (!isListStackEmpty(&stack)) {
            popStackList(&stack);
        }
    }
    
    // Вспомогательная функция для проверки пустоты стека
    bool isListStackEmpty(ListStack* stack) {
        return s->top == nullptr;
    }
};

// Тесты для стека на связном списке с использованием фикстуры

// Тест создания пустого стека на списке
TEST_F(ListStackTest, CreateListStack_EmptyStack_ReturnValidVal) {
    EXPECT_EQ(stack.top, nullptr);
    EXPECT_EQ(stack.size, 0);
}

// Тест добавления одного элемента в стек на списке
TEST_F(ListStackTest, PushStackList_SingleElement_ReturnValidVal) {
    pushStackList(&stack, 1);
    EXPECT_EQ(stack.top->data, 1);
    EXPECT_EQ(stack.top->next, nullptr);
    EXPECT_EQ(stack.size, 1);
}

// Тест добавления нескольких элементов в стек на списке
TEST_F(ListStackTest, PushStackList_SomeElements_ReturnValidVal) {
    for (int i = 1; i <= 5; i++) {
        pushStackList(&stack, i);
    }
    
    EXPECT_EQ(stack.top->data, 5);
    EXPECT_EQ(stack.size, 5);
}

// Тест извлечения элемента из стека на списке
TEST_F(ListStackTest, PopStackList_SingleElement_ReturnValidVal) {
    pushStackList(&stack, 1);
    int val = popStackList(&stack);
    EXPECT_EQ(val, 1);
    EXPECT_EQ(stack.top, nullptr);
    EXPECT_EQ(stack.size, 0);
}

// Тест извлечения из пустого стека на списке
TEST_F(ListStackTest, PopStackList_EmptyStack_ReturnErrorCode) {
    EXPECT_EQ(popStackList(&stack), -1);
}

// Тест просмотра верхнего элемента стека на списке
TEST_F(ListStackTest, PeekList_SingleElement_ReturnValidVal) {
    pushStackList(&stack, 1);
    EXPECT_EQ(peekList(&stack), 1);
    EXPECT_EQ(stack.size, 1);
}

// Тесты для стека на массиве

// Тест создания пустого стека на массиве
TEST_F(ArrayStackTest, CreateArrayStack_EmptyStack_ReturnValidVal) {
    EXPECT_EQ(stack.top, -1);
}

// Тест добавления одного элемента в стек на массиве
TEST_F(ArrayStackTest, PushArray_SingleElement_ReturnValidVal) {
    pushArray(&stack, 1);
    EXPECT_EQ(stack.top, 0);
    EXPECT_EQ(stack.data[0], 1);
}

// Тест добавления нескольких элементов в стек на массиве
TEST_F(ArrayStackTest, PushArray_SomeElements_ReturnValidVal) {
    for (int i = 0; i < 5; i++){
        pushArray(&stack, i + 1);
    }
    EXPECT_EQ(stack.top, 4);
    EXPECT_EQ(stack.data[0], 1);
    EXPECT_EQ(stack.data[1], 2);
    EXPECT_EQ(stack.data[2], 3);
    EXPECT_EQ(stack.data[3], 4);
    EXPECT_EQ(stack.data[4], 5);
}

// Тест переполнения стека на массиве
TEST_F(ArrayStackTest, PushArray_OverflowStack_ReturnValidVal) {
    // Заполняем стек до предела
    for (int i = 0; i < MAX_STACK_SIZE; i++) {
        pushArray(&stack, i);
    }
    
    int before_top = stack.top;
    pushArray(&stack, 1);
    EXPECT_EQ(stack.top, before_top);
}

// Тест извлечения элемента из стека на массиве
TEST_F(ArrayStackTest, PopArray_SingleElement_ReturnValidVal) {
    pushArray(&stack, 1);
    int val = popArray(&stack);
    EXPECT_EQ(val, 1);
    EXPECT_EQ(stack.top, -1);
}

// Тест извлечения из пустого стека на массиве
TEST_F(ArrayStackTest, PopArray_EmptyStack_ReturnErrorCode) {
    EXPECT_EQ(popArray(&stack), -1);
}

// Тест просмотра верхнего элемента стека на массиве
TEST_F(ArrayStackTest, PeekArray_SingleElement_ReturnValidVal) {
    pushArray(&stack, 1);
    EXPECT_EQ(peekArray(&stack), 1);
    EXPECT_EQ(stack.top, 0);
}

// Главная функция запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
