#pragma once

#include <iostream>
#include <utility>

class WordCard {
public:
	WordCard() = default;
	explicit WordCard(const std::string& word);
	WordCard(const WordCard&);
	WordCard& operator=(const WordCard& other);
	WordCard(WordCard&& card) noexcept;
	WordCard& operator=(WordCard&& other) noexcept;
	~WordCard() = default;
	[[nodiscard]] std::string GetWord() const;
	[[nodiscard]] size_t GetCounter() const;
	void IncCounter();
	bool operator==(const WordCard& other) const;
	bool operator!=(const WordCard& other) const;
	friend bool operator<(const WordCard& first, const WordCard& second);

private:
	std::string word_;
	size_t counter_ = 1;

};
WordCard::WordCard(const std::string& word) {
	word_ = word;
	counter_ = 1;
}
WordCard::WordCard(const WordCard& card) {
	word_ = card.word_;
	counter_ = card.counter_;
}
WordCard& WordCard::operator=(const WordCard& other) = default;
WordCard::WordCard(WordCard && card) noexcept {
	word_ = std::move(card.word_);
	counter_ = card.counter_;
}
WordCard& WordCard::operator=(WordCard && other) noexcept {
	word_ = std::move(other.word_);
	counter_ = other.counter_;
	return *this;
}
std::string WordCard::GetWord() const {
	return word_;
}
size_t WordCard::GetCounter() const {
	return counter_;
}
void WordCard::IncCounter() {
	counter_++;
}
bool WordCard::operator==(const WordCard & other)const {
	return word_ == other.word_ && counter_ == other.counter_;
}
bool WordCard::operator!=(const WordCard & other)const {
	return !(*this == other);
}

bool operator<(const WordCard & first, const WordCard & second) {
	return first.GetWord() < second.GetWord();

