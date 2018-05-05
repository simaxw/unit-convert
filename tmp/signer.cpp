#include <iostream>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/osrng.h>
#include <cryptopp/eccrypto.h>
#include <cryptopp/oids.h>
#include <cryptopp/files.h>
#include <cryptopp/ecpoint.h>

using namespace CryptoPP;
using namespace std;

int main(int argc, char *argv[]) {
  if ( argc < 2 ) {
    cerr << "Give Message to sign" << endl;
    return 1;
  }
  AutoSeededRandomPool prng;

  FileSource fs("ec.private.key", true);
  ECDSA<ECP, SHA1>::PrivateKey privkey;
  privkey.Load(fs);

  if ( !privkey.Validate( prng, 3 ) ) {
    cerr << "Private Key Validation failed" << endl;
    return 1;
  }

  ECDSA<ECP, SHA1>::Signer signer(privkey);
  string message = string(argv[1]);
  string signature;

  StringSource s(message, true,
      new SignerFilter(prng, signer, new StringSink(
          signature)));

  ofstream f_sig_out("signed.dat");
  f_sig_out << signature;
  f_sig_out.close();

  return 0;

  //FileSource fspub("ec.public.key", true);
  //ECDSA<ECP, SHA1>::PublicKey pubkey;
  //pubkey.Load(fspub);

  //ECDSA<ECP, SHA1>::Verifier verifier(pubkey);

  //bool result = false;

  //StringSource s_verify( signature+message, true,
  //    new SignatureVerificationFilter(
  //      verifier, new ArraySink( (byte*)&result, sizeof(result) ) ) );

  //cout << result << endl;


  /*
  CryptoPP::AutoSeededRandomPool prng;
  CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA1>::PrivateKey privkey;
  privkey.Initialize( prng, CryptoPP::ASN1::secp160r1() );

  CryptoPP::FileSink fs( "private.der", true );
  privkey.Save(fs);

  CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA1>::PublicKey pubkey;
  privkey.MakePublicKey(pubkey);
  const CryptoPP::ECP::Point& q = pubkey.GetPublicElement();
  pubkey.Initialize( CryptoPP::ASN1::secp160r1(), q );

  CryptoPP::FileSink fspub( "public.der", true );
  pubkey.Save(fspub);
  */

  /*
  CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA1>::Signer signer(privkey);

  if ( !signer.AccessKey().Validate( prng, 3 ) ) {
    std::cerr << "Failed" << std::endl;
    return 1;
  }
  */

  /*
  CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA1>::PrivateKey privkey;
  privkey.Initialize( prng, CryptoPP::ASN1::secp160r1() );

  if ( !privkey.Validate( prng, 3 ) ) {
    std::cerr << "Failed" << std::endl;
    return 1;
  }

  const CryptoPP::Integer& x = privkey.GetPrivateExponent();

  std::cout << "Done. Exponent=" << x << std::endl;
  */
}
