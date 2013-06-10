@echo off
@echo Creating Doc...
"C:\Program Files (x86)\richfeit\CppDoc\cppdoc_cmd.exe" -percent -title=PowerGrid -classdir=projects -module="cppdoc-standard" -extensions="c,cpp,cxx,cc,h,hpp,hxx" -languages="c=cpp,cc=cpp,cpp=cpp,cs=csharp,cxx=cpp,h=cpp,hpp=cpp,hxx=cpp,java=java" -enable-author=false -enable-deprecations=true -enable-since=true -enable-version=false -file-links-for-globals=false -generate-deprecations-list=true -generate-hierarchy=true -header-background-dark="#ccccff" -header-background-light="#eeeeff" -include-private=false -include-protected=true -index-file-base=index -overview-html=overview.html -reduce-summary-font=true -selected-text-background=navy -selected-text-foreground=white -separate-index-pages=false -show-cppdoc-version=false -show-timestamp=false -summary-html=project.html -suppress-details=false -suppress-frames-links=false -table-background=white -wrap-long-lines=false ..\src CppDoc\index.html

pause
@echo Done!
@echo on