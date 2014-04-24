#include <node.h>
#include <v8.h>

using namespace v8;

int get_hash_code(const char* str)
{
  int hash1 = 5381;
  int hash2 = hash1;

  int c;
  const char* s = str;
  while ((c = s[0]) != 0) {
    hash1 = ((hash1 << 5) + hash1) ^ c;
    c = s[1];
    if (c == 0) break;
    hash2 = ((hash2 << 5) + hash2) ^ c;
    s += 2;
  }

  return hash1 + (hash2 * 1566083941);
}

Handle<Value> GetHashCode(const Arguments& args)
{
  HandleScope scope;

  String::Utf8Value s(args[0]->ToString());
  return scope.Close(Integer::New(get_hash_code(*s)));
}

void init(Handle<Object> exports, Handle<Object> module)
{
  module->Set(String::NewSymbol("exports"),
      FunctionTemplate::New(GetHashCode)->GetFunction());
}

NODE_MODULE(get_hash_code, init)
