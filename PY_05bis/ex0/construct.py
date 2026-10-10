import sys
import site
# print(sys.prefix)
# print(type(sys.prefix))
# print(sys.prefix.split("/")[-1])
# sys.prefix.split("/")[-1]
ambiente = sys.prefix
inside_lab: bool = False
inside_lab = (ambiente != "/opt/pyenv/versions/3.11.15")
print(inside_lab) 
if inside_lab:  # LABORATORIO
    print("LABORATORY STATUS: The laboratory is sealed")
    print(f"Current Python: {sys.executable}")
    print(f"Virtual Environment: {sys.prefix.split('/')[-1]}")
    print(f"Environment Path: {sys.prefix}\n") 
    print("SUCCESS: You are working in an isolated environment!")
    print("Safe to install reagents without affecting")
    print("the global system.\n")
    print(f"Reagent installation path:")
    # print(f"{sys.prefix}/lib/python3.11/site-packages")
    print(f"{site.getsitepackages()[0]}")
else:  # FUORI
    print("LABORATORY STATUS: You are working in the open")
    print(f"Current Python: {sys.executable}")
    print("Virtual Environment: None detected")
    print("Every reagent you install here leaks into the whole system.")
