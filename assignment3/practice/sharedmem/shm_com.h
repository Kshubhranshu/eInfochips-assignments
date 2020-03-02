#define TEXT_SIZ 2048
void * shared_memory;
struct shared_use_st
{
	int written_by_you;
	char some_text[TEXT_SIZ];
};


