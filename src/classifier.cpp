#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <memory>
#include <sstream>

using namespace std;

class Trie {
private:
    struct TrieNode {
        map<char, TrieNode*> children;
        bool isEndOfWord;

        TrieNode() : isEndOfWord(false) {}
    };

    TrieNode* root;

    void insert(TrieNode* node, const string& word, size_t idx = 0) {
        if (idx == word.size()) {
            node->isEndOfWord = true;
            return;
        }
        if (node->children.find(word[idx]) == node->children.end()) {
            node->children[word[idx]] = new TrieNode();
        }
        insert(node->children[word[idx]], word, idx + 1);
    }

    // Verifică dacă un prefix este valid (nu apare în cuvintele din Fail)
    bool isValidPrefix(const string& prefix, const vector<string>& fail_words) {
        for (const auto& fail_word : fail_words) {
            if (fail_word.find(prefix) == 0) { // Dacă Fail începe cu acest prefix
                return false;
            }
        }
        return true;
    }

    // Găsește prefixul minim valid pentru un cuvânt
    string findMinimalPrefix(const string& word, const vector<string>& fail_words) {
        for (size_t i = 1; i <= word.size(); ++i) {
            string prefix = word.substr(0, i);
            if (isValidPrefix(prefix, fail_words)) {
                return prefix + ".*";  // Adăugăm .* pentru a permite orice caractere după prefix
            }
        }
        return "";
    }

public:
    Trie() : root(new TrieNode()) {}

    void insert(const string& word) {
        insert(root, word);
    }

    string generateRegex(const vector<string>& accept_words, const vector<string>& fail_words) {
        string regex_pattern;
        set<string> unique_prefixes;

        // Obținem prefixele minime pentru cuvintele acceptate
        for (const string& word : accept_words) {
            string prefix = findMinimalPrefix(word, fail_words);
            if (!prefix.empty()) {
                unique_prefixes.insert(prefix);
            }
        }

        // Construim expresia regulată
        bool first = true;
        for (const auto& prefix : unique_prefixes) {
            if (!first) {
                regex_pattern += "|";  // Adăugăm operatorul OR pentru a combina prefixele
            }
            regex_pattern += prefix;
            first = false;
        }

        return regex_pattern;
    }
};

string createOptimizedPattern(const vector<string>& accept_words, const vector<string>& fail_words) {
    if (accept_words.empty()) return "";
    if (accept_words.size() == 1) return accept_words[0] + ".*";  // Dacă avem un singur cuvânt, adăugăm .* la final

    Trie trie;
    for (const string& word : accept_words) {
        trie.insert(word);
    }

    return trie.generateRegex(accept_words, fail_words);
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error opening files" << endl;
        return 1;
    }

    int cnt_accept, cnt_fail, len_string;
    fin >> cnt_accept >> cnt_fail >> len_string;

    vector<string> accept_words(cnt_accept);
    vector<string> fail_words(cnt_fail);

    for (int i = 0; i < cnt_accept; i++) {
        fin >> accept_words[i];
    }

    for (int i = 0; i < cnt_fail; i++) {
        fin >> fail_words[i];
    }

    fout << "regex" << endl;
    string regex = createOptimizedPattern(accept_words, fail_words);
    fout << regex << endl;

    fin.close();
    fout.close();
    return 0;
}
