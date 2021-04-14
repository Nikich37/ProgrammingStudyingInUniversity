#pragma once

#include <iostream>
#include <map>

#include "bidirectional_list_on_array.h"
#include "word_card.h"
#include "file_reader.h"

class Vocabulary {
public:
	void ReadFileToCards(const std::string& file_path);
	static WordCard* ConvertStringToWordCard(const std::string& str);
	void MakeFrequencyVocab();
	void SortWords();
	static std::map<std::string, size_t> CopyToMap();

private:
	containers::BiDirectionalList<WordCard*> list_word_cards;
};
void Vocabulary::ReadFileToCards(const std::string& file_path) {
	FileReader fr;
	auto words = fr.ReadWords(file_path);
}
WordCard* Vocabulary::ConvertStringToWordCard(const std::string& str) {
	auto* ptr = new WordCard(str);
	return ptr;
}
std::map<std::string, size_t> Vocabulary::CopyToMap() {
	return std::map<std::string, size_t>();
}

