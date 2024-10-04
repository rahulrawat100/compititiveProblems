class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int numOfPlayers = skill.size();
      if(numOfPlayers%2==1)
         return -1;      
      int sumOfSkills=0;

      for(int i=0; i<numOfPlayers;i++)
      {
        sumOfSkills+=skill[i];
      }

      if(sumOfSkills%(numOfPlayers/2)!=0)
         return -1;
      int targetSkill = 2*sumOfSkills/numOfPlayers;
       
      unordered_map<int, int> skillsUpto;
      long long TotalChemistry=0;
      int groups=0;
      for(int i=0; i<numOfPlayers; i++)
      {
         auto it = skillsUpto.find(targetSkill-skill[i]);
         if(it==skillsUpto.end()||it->second==0)
            skillsUpto[skill[i]]++;
         else
         {
             TotalChemistry += skill[i]*(long long)(targetSkill-skill[i]);
             skillsUpto[targetSkill-skill[i]]--;
              groups++;
         }   
      }
      return groups<numOfPlayers/2?-1:TotalChemistry;
    }
};