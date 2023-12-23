
rm /mestrado/projetos/scp/obj/scp.main.o
rm /mestrado/projetos/scp/obj/scp.elemsubsets.o
rm /mestrado/projetos/scp/obj/scp.grasp.o
rm /mestrado/projetos/scp/obj/scp.heuconstrutive.randomized.o
rm /mestrado/projetos/scp/obj/scp.heuconstrutive.cost.o
rm /mestrado/projetos/scp/obj/scp.localsearch.o
rm /mestrado/projetos/scp/obj/scp.tabusearch.o
rm /mestrado/projetos/scp/obj/scp.functions.o
rm /mestrado/projetos/scp/bin/scp

g++ -c /mestrado/projetos/scp/source/scp.main.cpp -o /mestrado/projetos/scp/obj/scp.main.o
g++ -c /mestrado/projetos/scp/source/scp.elemsubsets.cpp -o /mestrado/projetos/scp/obj/scp.elemsubsets.o
g++ -c /mestrado/projetos/scp/source/scp.grasp.cpp -o /mestrado/projetos/scp/obj/scp.grasp.o
g++ -c /mestrado/projetos/scp/source/scp.heuconstrutive.randomized.cpp -o /mestrado/projetos/scp/obj/scp.heuconstrutive.randomized.o
g++ -c /mestrado/projetos/scp/source/scp.heuconstrutive.cost.cpp -o /mestrado/projetos/scp/obj/scp.heuconstrutive.cost.o
g++ -c /mestrado/projetos/scp/source/scp.heuconstrutive.cost.coverage.cpp -o /mestrado/projetos/scp/obj/scp.heuconstrutive.cost.coverage.o
g++ -c /mestrado/projetos/scp/source/scp.localsearch.cpp -o /mestrado/projetos/scp/obj/scp.localsearch.o
g++ -c /mestrado/projetos/scp/source/scp.tabusearch.cpp -o /mestrado/projetos/scp/obj/scp.tabusearch.o
g++ -c /mestrado/projetos/scp/source/scp.functions.cpp -o /mestrado/projetos/scp/obj/scp.functions.o

g++ /mestrado/projetos/scp/obj/scp.main.o /mestrado/projetos/scp/obj/scp.elemsubsets.o /mestrado/projetos/scp/obj/scp.grasp.o /mestrado/projetos/scp/obj/scp.heuconstrutive.randomized.o /mestrado/projetos/scp/obj/scp.heuconstrutive.cost.o /mestrado/projetos/scp/obj/scp.heuconstrutive.cost.coverage.o   /mestrado/projetos/scp/obj/scp.localsearch.o /mestrado/projetos/scp/obj/scp.tabusearch.o /mestrado/projetos/scp/obj/scp.functions.o -o /mestrado/projetos/scp/bin/scp

