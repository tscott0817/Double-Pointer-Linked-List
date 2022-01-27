#define PARTNAME_LEN 32

typedef struct PartRecordStruct {
    int partNumber;
    int quantity;
    char partName[PARTNAME_LEN];
    struct PartRecordStruct *next;
} PartRecord;

int insertPart(PartRecord **head, int partNumber, int quantity, char *partName);

int deletePart(PartRecord **head, int partNumber);

PartRecord *findPart(PartRecord *head, int partNumber);

void printParts(PartRecord *theList);

void printPartList(PartRecord *theList);