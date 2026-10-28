# List generic local / parameter names (a, p, arg2, tmp...) per C file, via the clang AST.
# usage: python3 tools/scripts/generic_locals.py [-v] [src/x.c ...]  (stderr: total decls, generic)
import subprocess,json,re,sys,glob,collections
GEN=re.compile(r'^(a\d*|arg\d*|r\d+|sp[0-9A-Fa-f]*[0-9][0-9A-Fa-f]*|tmp\d*|temp\d*|var_?\w*|unk\w*|[a-hj-mo-wA-Z]|v\d+|t\d+|p\d+|s\d+|b\d+|c\d+|x\d+|y\d+)$')
OK={'i','j','k','x','y','z','w','h','n'}
DETAIL="-v" in sys.argv; sys.argv=[a for a in sys.argv if a!="-v"]
files=sys.argv[1:] or sorted(glob.glob('src/**/*.c',recursive=True))
tot=0;gen=0;out=collections.defaultdict(list)
for f in files:
    p=subprocess.run(['clang','-Xclang','-ast-dump=json','-fsyntax-only','-Iinclude','-w','--target=arm-none-eabi',f],capture_output=True,text=True)
    try: ast=json.loads(p.stdout)
    except Exception: print('ERR',f,file=sys.stderr); continue
    for d in ast.get('inner',[]):
        if d.get('kind')!='FunctionDecl' or 'inner' not in d: continue
        if not any(x.get('kind')=='CompoundStmt' for x in d['inner']): continue
        loc=d.get('loc',{})
        if loc.get('includedFrom'): continue
        stack=[d]
        while stack:
            n=stack.pop()
            for c in n.get('inner',[]) or []:
                if c.get('kind') in ('ParmVarDecl','VarDecl') and c.get('name'):
                    nm=c['name']; tot+=1
                    if nm not in OK and GEN.match(nm):
                        gen+=1; out[f].append((d['name'],nm))
                stack.append(c)
print(tot,gen,file=sys.stderr)
for f,l in sorted(out.items(),key=lambda x:-len(x[1])):
    print(len(l),f, " ".join(sorted(set(a+":"+b for a,b in l))) if DETAIL else "")
