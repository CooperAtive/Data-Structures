typedef struct WordSearch
{
    char **grid;
    void (*solver) (struct WordSearch self, char *start);
}
WordSearch;

WordSearch *WordSearch_new(const char *name)
{
    WordSearch *ws = (WordSearch *) malloc(sozeof(WordSearch));
    
    WordSearch_init(ws, name);
    
    return ws;
}

void WordSearch_init(WordSearch *self, const char *name)
{
    self->name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(self->name, name);
    
    self->solver = WordSearch_solver;
}