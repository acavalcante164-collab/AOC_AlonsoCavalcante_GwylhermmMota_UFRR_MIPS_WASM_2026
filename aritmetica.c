#include <stdint.h>
#include <stdbool.h>

//MACRO PARA EXPORTAR A FUNCAO PARA WEBASSEMBLY
#define WASM_EXPORT __attribute__((visibility("default")))

//SOMA BASICA (VULNERAVEL A OVERFLOW)
WASM_EXPORT int32_t soma(int32_t a, int32_t b){
    return a + b;
}

//TODO: IMPLEMENTAR DETECCAO LOGICA DE OVERFLOW (COMO O MIPS FARIA)
//RETORNA O RESULTADO. SE HOUVER OVERFLOW, *teve_overflow = true.
WASM_EXPORT int32_t soma_segura(int32_t a, int32_t b, bool* teve_overflow){ 
    *teve_overflow = false;
//DICA: ANALISE OS SINAIS DOS OPERANDOS 'A' E 'B' E COMPARE
//COM O SINAL DO RESULTADO. LEMBRE-SE DO MSB(MOST SIGNIFICANT BIT)
    int32_t resultado = a + b;
    // SE A POSITIVO E B TAMBEM POSITO E O RESULTADO GERADO DER NEGATIVO HOUVE UM OVERFLOW OU SE A NEGATIVO E B TAMBEM NEGATIVO E O RESULTADO GERAR UM RESULTADO POSITVO OUVE UM OVERFLOW
    if ((a > 0 && b > 0 && resultado < 0) || (a < 0 && b < 0 && resultado > 0)) {
        *teve_overflow = true;
    }
    return resultado;
}
WASM_EXPORT int32_t sub_segura (int32_t a, int32_t b, bool* teve_overflow){
    *teve_overflow = false;
    int32_t resultado = a - b;
    if ((a > 0 && b < 0 && resultado < 0) || (a < 0 && b > 0 && resultado > 0)) {
        *teve_overflow = true;
    }
    return resultado;
}
WASM_EXPORT int32_t mul_segura (int32_t a, int32_t b, bool* teve_overflow){
    *teve_overflow = false;
    int32_t resultado = a * b;
    if (a != 0 && (resultado /a) != b){
        *teve_overflow = true;
    }
    return resultado;
}
//TODO: IMPLEMENTAR 'sub' e 'sub-segura'
WASM_EXPORT int32_t sub (int32_t a, int32_t b){
    return a - b;
}
WASM_EXPORT int32_t mul (int32_t a, int32_t b){
    return a * b;
}
//TODO: IMPLEMENTAR 'mul' e 'mul-segura'

