#pragma once

#include <cassert>
#include <stdexcept>
#include <utility>
#include <vector>

namespace containers {

    template<typename T>
    class BiDirectionalList {
    public:
        BiDirectionalList() = default;
        explicit BiDirectionalList(size_t size) : BiDirectionalList(size, T()) {}
        BiDirectionalList(size_t size, const T& value) {
            Relocate(size);
            size_ = size;
            for (size_t i = 0; i < size; i++) {
                data_[i] = value;
            }
        }
        BiDirectionalList(BiDirectionalList&& vec) noexcept {
            Swap(*this, vec);
        }

        BiDirectionalList(const std::initializer_list<T>& list) {
            for (const auto& elem : list) {
                PushBack(elem);
            }
        }

        BiDirectionalList(const BiDirectionalList& vec)
            : BiDirectionalList(vec.size_) {
            for (size_t i = 0; i < vec.size_; i++) {
                data_[i] = vec.data_[i];
            }
        }

        ~BiDirectionalList() {
            delete[] data_;
        }

        BiDirectionalList& operator=(BiDirectionalList<T>&& vec) noexcept {
            Swap(*this, vec);
            return *this;
        }

        BiDirectionalList& operator=(const BiDirectionalList<T>& vec) {
            if (this == &vec) {
                return *this;
            }
            BiDirectionalList<T> temp(vec);
            Swap(*this, temp);
            return *this;
        }

        bool operator==(BiDirectionalList<T> list) {
            if (size_ != list.size_) {
                return false;
            }
            for (int i = 0; i < size_; i++) {
                if (data_[i] != list.data_[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(BiDirectionalList<T> list) {
            return !((*this) == list);
        }

        void PushBack(const T& value) {
            if (size_ == capacity_) {
                Relocate(capacity_ * GROWTH_FACTOR);
            }
            data_[size_] = std::move(value);
            size_++;
        }

        void PushFront(const T& value) {
            if (size_ == capacity_) {
                Relocate(capacity_ * GROWTH_FACTOR);
            }
            size_++;
            for (int i = size_ - 1; i > 0; i--) {
                data_[i] = data_[i - 1];
            }
            data_[0] = value;
        }

        void PushFront(T&& value) {
            if (size_ == capacity_) {
                Relocate(capacity_ * GROWTH_FACTOR);
            }
            size_++;
            for (int i = size_ - 1; i > 0; i--) {
                data_[i] = data_[i - 1];
            }
            data_[0] = std::move(value);
        }

        void PopBack() {
            if (size_ == 0) {
                throw std::out_of_range("Vector is already empty");
            }
            size_--;
        }
        void PopFront() {
            if (size_ == 0) {
                throw std::out_of_range("Vector is already empty");
            }
            for (int i = 1; i < size_; i++) {
                data_[i - 1] = data_[i];
            }
            size_--;
        }

        void Clear() {
            size_ = 0;
        }

        bool IsEmpty() {
            return size_ == 0;
        }

        std::vector<T> ToVector() {
            std::vector<T> result;
            result.reserve(size_);
            for (int i = 0; i < size_; i++) {
                result.push_back(data_[i]);
            }
            return result;
        }

        T* operator[](size_t index) {
            return &const_cast<T&>(const_cast<const BiDirectionalList&>(*this).operator[](
                index));
        }
        const T* operator[](size_t index) const {
            if (index >= size_) {
                throw std::out_of_range("Index out of range");
            }
            return &data_[index];
        }
        [[nodiscard]] size_t Size() const {
            return size_;
        }

        friend void Swap(BiDirectionalList<T>& a, BiDirectionalList<T>& b) {
            std::swap(a.data_, b.data_);
            std::swap(a.size_, b.size_);
            std::swap(a.capacity_, b.capacity_);
        }

        T* Front() {
            return &data_[0];
        }

        const T* Front() const {
            return &data_[0];
        }

        T* Back() {
            return &data_[size_ - 1];
        }

        const T* Back() const {
            return &data_[size_ - 1];
        }

        void InsertBefore(size_t index, const T& value) {
            if (size_ == capacity_) {
                Relocate(capacity_ * GROWTH_FACTOR);
            }
            size_++;
            for (int i = size_ - 1; i > index; i--) {
                data_[i] = data_[i - 1];
            }
            data_[index] = value;
        }

        void InsertBefore(size_t index, T&& value) {
            if (size_ == capacity_) {
                Relocate(capacity_ * GROWTH_FACTOR);
            }
            size_++;
            for (int i = size_ - 1; i > index; i--) {
                data_[i] = data_[i - 1];
            }
            data_[index] = std::move(value);
        }


        void InsertAfter(size_t index, T&& value) {
            if (size_ == capacity_) {
                Relocate(capacity_ * GROWTH_FACTOR);
            }
            size_++;
            for (int i = size_ - 1; i > index + 1; i--) {
                data_[i] = data_[i - 1];
            }
            data_[index + 1] = std::move(value);
        }

        void InsertAfter(size_t index, const T& value) {
            if (size_ == capacity_) {
                Relocate(capacity_ * GROWTH_FACTOR);
            }
            size_++;
            for (int i = size_ - 1; i > index + 1; i--) {
                data_[i] = data_[i - 1];
            }
            data_[index + 1] = value;
        }
            void Erase(size_t index) {
            if (size_ == 0) {
                throw std::out_of_range("Vector is already empty");
            }
            for (int i = index; i < size_; i++) {
                data_[i - 1] = data_[i];
            }
            size_--;
        }

        int Find(const T& value) {
            for (int i = 0; i < size_; i++) {
                if (data_[i] == value) {
                    return i;
                }
            }
            return -1;
        }

        std::vector<int> FindAll(const T& value) {
            std::vector<int> result;
            for (int i = 0; i < size_; i++) {
                if (data_[i] == value) {
                    result.push_back(i);
                }
            }
            return result;
        }

    private:
        void Relocate(size_t new_capacity) {
            if (new_capacity < size_) {
                throw std::runtime_error("Bad relocation");
            }

            capacity_ = new_capacity;
            T* buf = new T[capacity_];
            for (size_t i = 0; i < size_; i++) {
                buf[i] = std::move(data_[i]);
            }

            delete[] data_;
            data_ = buf;
        }

        size_t size_{ 0 };
        T* data_ = new T[MIN_CAPACITY];
        size_t capacity_{ MIN_CAPACITY };
        static const size_t MIN_CAPACITY = 10;
        static const size_t GROWTH_FACTOR = 2;
    };

}  