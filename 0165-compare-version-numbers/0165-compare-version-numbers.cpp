class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        int n1 = size(version1), n2 = size(version2);
        int j = 0, k = 0;
        while (j < n1 && k < n2)
        {
            string temp1 = "", temp2 = "";
            while(j<n1 && version1[j]=='0')j++;  while(k<n2 && version2[k]=='0')k++;
            
            while (j < n1 && version1[j] != '.')
                    temp1 += version1[j++];
            while (k < n2 && version2[k] != '.')
                    temp2 += version2[k++];

            if (temp1.size() < temp2.size())
                return -1;
            else if (temp1.size() > temp2.size())
                return 1;
            else if (temp1 < temp2)
                return -1;
            else if (temp1 > temp2)
                return 1;
            j++;
            k++;
        }

        while (j < n1) // Handle remaining digits in version1
        {
            if (version1[j] != '0' && version1[j] != '.')return 1; // version1 is greater
            j++;
        }

        while (k < n2) // Handle remaining digits in version2
        {
            if (version2[k] != '0' && version2[k] != '.')return -1; // version2 is greater
            k++;
        }

        return 0; // Both versions are equal
    }
};
