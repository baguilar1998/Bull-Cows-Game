class LetterSet {
    public:
        LetterSet();
        ~LetterSet();
        void AddLetter(char Letter);
        bool ContainsLetter(char Letter);
        void ResetSet();

    private:
        bool *Set;
};