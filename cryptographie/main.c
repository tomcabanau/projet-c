#include <stdio.h>

char chiffrement(char caractere, int cle) {
    if ('A' <= caractere && caractere <= 'Z') {
        return (caractere - 'A' + cle) % 26 + 'A';
    } else {
        return caractere;
    }
}

char dechiffrement(char caractere, int cle) {
    if ('A' <= caractere && caractere <= 'Z') {
        return (caractere - 'A' - cle + 26) % 26 + 'A';
    } else {
        return caractere;
    }
}

void analyser_frequence(char *texte, float *frequences) {
    int total_lettres = 0;

    for (int i = 0; texte[i] != '\0'; i++) {
        char caractere = texte[i];
        if ('A' <= caractere && caractere <= 'Z') {
            frequences[caractere - 'A']++;
            total_lettres++;
        }
    }

    for (int i = 0; i < 26; i++) {
        frequences[i] = (frequences[i] / total_lettres) * 100;
    }
}

int calculer_cle(float *frequences) {
    int lettre_la_plus_frequente = 0;

    for (int i = 1; i < 26; i++) {
        if (frequences[i] > frequences[lettre_la_plus_frequente]) {
            lettre_la_plus_frequente = i;
        }
    }

    int cle = (lettre_la_plus_frequente - ('E' - 'A') + 26) % 26;
    return cle;
}

void decrypter_texte(char *texte, int cle) {
    for (int i = 0; texte[i] != '\0'; i++) {
        printf("%c", dechiffrement(texte[i], cle));
    }
    printf("\n");
}

int main() {
    char texte_clair[] = "VERCINGETORIX";
    int cle_chiffrement = 3;
    printf("Texte chiffré: ");
    for (int i = 0; texte_clair[i] != '\0'; i++) {
        printf("%c", chiffrement(texte_clair[i], cle_chiffrement));
    }
    printf("\n");
    printf("Texte déchiffré: ");
    for (int i = 0; texte_clair[i] != '\0'; i++) {
        printf("%c", dechiffrement(chiffrement(texte_clair[i], cle_chiffrement), cle_chiffrement));
    }
    printf("\n");
    char texte_analyse[] = "ZNVGER PBEORNH, FHE HA NEOER CREPUR, GRANVG RA FBA ORP HA SEBZNTR. ZNVGER ERANEQ CNE Y'BQRHE NYYRPUR, YHV GVAG N CRH CERF PR YNATNTR : RG OBAWBHE ZBAFVRHE QH PBEORNH. DHR IBHF RGRF WBYV! DHR IBHF ZR FRZOYRM ORNH! FNAF ZRAGVE, FV IBGER ENZNTR FR ENCCBEGR N IBGER CYHZNTR IBHF RGRF YR CURAVK QRF UBGRF QR PRF OBVF. N PRF ZBGF YR PBEORNH AR FR FRAG CNF QR WBVR; RG CBHE ZBAGERE FN ORYYR IBVK, VY BHIER HA YNETR ORP YNVFFR GBZORE FN CEBVR. YR ERANEQ F'RA FNVFVG RG QVG : ZBA OBA ZBAFVRHE, NCERARM DHR GBHG SYNGGRHE IVG NH QRCRAF QR PRYHV DHV Y'RPBHGR : PRGGR YRPBA INHG OVRA HA SEBZNTR FNAF QBHGR. YR PBEORNH UBAGRHK RG PBASHF WHEN ZNVF HA CRH CYHF GNEQ, DH'BA AR Y'L CERAQENVG CYHF.";
    float frequences[26] = {0};
    analyser_frequence(texte_analyse, frequences);
    printf("\nFréquence d'apparition des lettres dans le texte chiffré:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %.2f%%\n", 'A' + i, frequences[i]);
    }
    int cle_calcul = calculer_cle(frequences);
    printf("\nClé de chiffrement estimée: %d\n", cle_calcul);
    printf("\nTexte déchiffré avec la clé estimée:\n");
    decrypter_texte(texte_analyse, cle_calcul);

    return 0;
}
