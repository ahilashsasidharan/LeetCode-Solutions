class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string, int> freqs;
        std::vector<std::vector<std::string>> buckets(words.size() + 1);
        std::vector<std::string> results;

        // start by going through the array and counting the occurences of each word
        for(const std::string& s : words){
            freqs[s]++;
        }

        // sort words into buckets for there frequency
        for(const auto& [word, freq] : freqs){
            buckets[freq].push_back(word);
        }

        // add to the result vector
        // go from the largest bucket to the smallest till you get K words
        int bucket = words.size();
        // can check bucket greater than 0 since the element 0 will always have no strings
        // since any string in words that is counded will have at least occurence of 1
        while(results.size() != k && bucket > 0){
            std::sort(buckets[bucket].begin(), buckets[bucket].end());
            int string = 0;
            while(results.size() != k && string < buckets[bucket].size()){
                results.push_back(buckets[bucket][string]);
                string++;
            }
            bucket--;            
        }

        return results;
    }
};