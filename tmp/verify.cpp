#include <iostream>
#include <fstream>
#include <sstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/osrng.h>
#include <cryptopp/eccrypto.h>
#include <cryptopp/oids.h>
#include <cryptopp/files.h>
#include <cryptopp/ecpoint.h>

using namespace CryptoPP;

int main(int argc, char *argv[]) {
  if ( argc < 3 ) {
    std::cerr << "Give Message and signature" << std::endl;
    return 1;
  }
  AutoSeededRandomPool prng;

  FileSource fspub("ec.public.key", true);
  ECDSA<ECP, SHA1>::PublicKey pubkey;
  pubkey.Load(fspub);

  if ( !pubkey.Validate( prng, 3 ) ) {
    std::cerr << "Public Key Validation failed" << std::endl;
    return 1;
  }

  ECDSA<ECP, SHA1>::Verifier verifier(pubkey);

  std::string message = std::string(argv[1]);

  std::ifstream f_sig_in(argv[2]);

  std::stringstream ss_sig_in;
  ss_sig_in << f_sig_in.rdbuf();
  std::string signature = ss_sig_in.str();
  f_sig_in.close();

  bool result = false;

  StringSource s_verify(
      signature+message,
      true,
      new SignatureVerificationFilter(
        verifier,
        new ArraySink( (byte*)&result, sizeof(result) )
      )
    );

  std::cout << result << std::endl;


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

  return 0;
}
