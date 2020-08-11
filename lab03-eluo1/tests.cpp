/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Spring 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/vdxo2w8
*/

#include <fstream>
#include <string>
#include <UnitTest++/UnitTest++.h>

#include "caesar.h"
#include "cipher.h"
#include "rotation.h"
#include "stream.h"
#include "substitution.h"
#include "test_utils.h"

using namespace std;

TEST(caesar_cipher_encryption) {
    Cipher* cipher = new CaesarCipher("");
    CHECK_EQUAL('A', cipher->encrypt('D')); // these arrows are pointers, similar to '.' in Python
    CHECK_EQUAL('B', cipher->encrypt('E'));
    CHECK_EQUAL('Z', cipher->encrypt('C'));
    CHECK_EQUAL('W', cipher->encrypt('Z'));
    delete cipher;
}

TEST(caesar_cipher_decryption) {
    Cipher* cipher = new CaesarCipher("");
    CHECK_EQUAL('D', cipher->decrypt('A'));
    CHECK_EQUAL('E', cipher->decrypt('B'));
    CHECK_EQUAL('C', cipher->decrypt('Z'));
    CHECK_EQUAL('Z', cipher->decrypt('W'));
    delete cipher;
}

TEST(rotation_cipher_encryption_4) {
    Cipher* cipher = new RotationCipher("4");
    CHECK_EQUAL('H', cipher->encrypt('D'));
    CHECK_EQUAL('I', cipher->encrypt('E'));
    CHECK_EQUAL('G', cipher->encrypt('C'));
    CHECK_EQUAL('D', cipher->encrypt('Z'));
    delete cipher;
}

TEST(rotation_cipher_decryption_4) {
    Cipher* cipher = new RotationCipher("4");
    CHECK_EQUAL('D', cipher->decrypt('H'));
    CHECK_EQUAL('E', cipher->decrypt('I'));
    CHECK_EQUAL('C', cipher->decrypt('G'));
    CHECK_EQUAL('Z', cipher->decrypt('D'));
    delete cipher;
}

TEST(rotation_cipher_encryption_neg2) {
    Cipher* cipher = new RotationCipher("-2");
    CHECK_EQUAL('B', cipher->encrypt('D'));
    CHECK_EQUAL('C', cipher->encrypt('E'));
    CHECK_EQUAL('Z', cipher->encrypt('B'));
    CHECK_EQUAL('X', cipher->encrypt('Z'));
}

TEST(rotation_cipher_decryption_neg2) {
    Cipher* cipher = new RotationCipher("-2");
    CHECK_EQUAL('D', cipher->decrypt('B'));
    CHECK_EQUAL('E', cipher->decrypt('C'));
    CHECK_EQUAL('B', cipher->decrypt('Z'));
    CHECK_EQUAL('Z', cipher->decrypt('X'));
    delete cipher;
}

TEST(substitution_cipher_encryption) {
    Cipher* cipher = new SubstitutionCipher("JZSPWARVIEHGDMOFQLBCNKTUYX");
    CHECK_EQUAL('P', cipher->encrypt('D'));
    CHECK_EQUAL('W', cipher->encrypt('E'));
    CHECK_EQUAL('S', cipher->encrypt('C'));
    CHECK_EQUAL('X', cipher->encrypt('Z'));
    delete cipher;
}

TEST(substitution_cipher_decryption) {
    Cipher* cipher = new SubstitutionCipher("JZSPWARVIEHGDMOFQLBCNKTUYX");
    CHECK_EQUAL('D', cipher->decrypt('P'));
    CHECK_EQUAL('E', cipher->decrypt('W'));
    CHECK_EQUAL('C', cipher->decrypt('S'));
    CHECK_EQUAL('Z', cipher->decrypt('X'));
    delete cipher;
}

TEST(stream_cipher_encryption) {
    Cipher* cipher = new StreamCipher("ACB");
    CHECK_EQUAL('E', cipher->encrypt('D'));
    CHECK_EQUAL('I', cipher->encrypt('E'));
    CHECK_EQUAL('I', cipher->encrypt('C'));
    CHECK_EQUAL('G', cipher->encrypt('Z'));
    delete cipher;
}

TEST(stream_cipher_decryption) {
    Cipher* cipher = new StreamCipher("ACB");
    CHECK_EQUAL('D', cipher->decrypt('E'));
    CHECK_EQUAL('E', cipher->decrypt('I'));
    CHECK_EQUAL('C', cipher->decrypt('I'));
    CHECK_EQUAL('Z', cipher->decrypt('G'));
    delete cipher;
}

int main() {
    return UnitTest::RunAllTests();
}
